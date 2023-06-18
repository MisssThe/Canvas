//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Elements/Mesh.h"
#include "../Include/General/Container/ContainSerialize/VectorSerialize.h"
#include "../Include/General/Debug.h"
#include "../Include/General/Container/Queue.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

void Mesh::Read(cereal::BinaryInputArchive &archive) {
    this->indices = VectorSerialize::Read<unsigned int>(archive);
    this->vertices = VectorSerialize::Read<float>(archive);
    this->normals = VectorSerialize::Read<float>(archive);
    this->tangents = VectorSerialize::Read<float>(archive);
    this->colors = VectorSerialize::Read<float>(archive);
    this->uv0s = VectorSerialize::Read<float>(archive);
    this->uv1s = VectorSerialize::Read<float>(archive);
    this->uv2s = VectorSerialize::Read<float>(archive);
}

void Mesh::Write(cereal::BinaryOutputArchive &archive) {
    VectorSerialize::Write(archive, this->indices);
    VectorSerialize::Write(archive, this->vertices);
    VectorSerialize::Write(archive, this->normals);
    VectorSerialize::Write(archive, this->tangents);
    VectorSerialize::Write(archive, this->colors);
    VectorSerialize::Write(archive, this->uv0s);
    VectorSerialize::Write(archive, this->uv1s);
    VectorSerialize::Write(archive, this->uv2s);
}

void Mesh::CustomMark() {
    CustomPtr::S_Mark(this->indices);
    CustomPtr::S_Mark(this->vertices);
    CustomPtr::S_Mark(this->normals);
    CustomPtr::S_Mark(this->tangents);
    CustomPtr::S_Mark(this->colors);
    CustomPtr::S_Mark(this->uv0s);
    CustomPtr::S_Mark(this->uv1s);
    CustomPtr::S_Mark(this->uv2s);
}

int Mesh::Size() const {
    int size = 0;
    if (this->vertices)
        size += this->vertices->MemorySize();
    if (this->normals)
        size += this->normals->MemorySize();
    if (this->tangents)
        size += this->tangents->MemorySize();
    if (this->colors)
        size += this->colors->MemorySize();
    if (this->uv0s)
        size += this->uv0s->MemorySize();
    if (this->uv1s)
        size += this->uv1s->MemorySize();
    if (this->uv2s)
        size += this->uv2s->MemorySize();
    return size;
}

void Mesh::Cache(std::string file) {
    //用Assimp加载mesh
    this->LoadMesh(file);
}

void Mesh::LoadMesh(const std::string& file) {
    //import 会将scene node mesh等一同析构掉
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(file, aiProcess_Triangulate);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
        Debug::Warn("Mesh Load","Mesh Load Failed [" + path + "]");
        return;
    }

    auto meshes = new Queue<aiMesh*>();
    auto nodes = new Queue<aiNode*>();
    nodes->Push(scene->mRootNode);

    while (nodes->Size() > 0) {
        nodes->IteratorWithRemove([&nodes, &meshes, &scene](aiNode *node) {
            for (int index = 0; index < node->mNumMeshes; ++index) {
                meshes->Push(scene->mMeshes[node->mMeshes[index]]);
            }
            for (int index = 0; index < node->mNumChildren; ++index) {
                nodes->Push(node->mChildren[index]);
            }
            return false;
        });
    }
    meshes->IteratorWithout([this](aiMesh* am) {
        for (int index = 0; index < am->mNumVertices; ++index) {
            this->vertices = new Vector<float>();
            this->vertices->Add(am->mVertices[index].x);
            this->vertices->Add(am->mVertices[index].y);
            this->vertices->Add(am->mVertices[index].z);

            if (am->HasNormals()) {
                this->normals = new Vector<float>();
                this->normals->Add(am->mNormals[index].x);
                this->normals->Add(am->mNormals[index].y);
                this->normals->Add(am->mNormals[index].z);
            }

            if (am->HasTangentsAndBitangents()) {
                this->tangents = new Vector<float>();
                this->tangents->Add(am->mTangents[index].x);
                this->tangents->Add(am->mTangents[index].y);
                this->tangents->Add(am->mTangents[index].z);
            }

            if (am->mColors[0]) {
                this->colors = new Vector<float>();
                this->colors->Add(am->mColors[0][index].r);
                this->colors->Add(am->mColors[0][index].g);
                this->colors->Add(am->mColors[0][index].b);
                this->colors->Add(am->mColors[0][index].a);
            }

            if (am->mTextureCoords[0]) {
                this->uv0s = new Vector<float>();
                this->uv0s->Add(am->mTextureCoords[0][index].x);
                this->uv0s->Add(am->mTextureCoords[0][index].y);
            }
            if (am->mTextureCoords[1]) {
                this->uv1s = new Vector<float>();
                this->uv0s->Add(am->mTextureCoords[1][index].x);
                this->uv0s->Add(am->mTextureCoords[1][index].y);
            }
            if (am->mTextureCoords[2]) {
                this->uv2s = new Vector<float>();
                this->uv0s->Add(am->mTextureCoords[2][index].x);
                this->uv0s->Add(am->mTextureCoords[2][index].y);
            }
        }
    });
}
