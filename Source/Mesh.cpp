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
    archive(this->memorySize);
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
    archive(this->memorySize);
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
    return this->memorySize;
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
    this->indices = new Vector<unsigned int>();
    this->vertices = new Vector<float>();
    this->normals = new Vector<float>();
    this->tangents = new Vector<float>();
    this->colors = new Vector<float>();
    this->uv0s = new Vector<float>();
    this->uv1s= new Vector<float>();
    this->uv2s= new Vector<float>();

    meshes->IteratorWithout([this](aiMesh* am) {
        for(unsigned int x = 0; x < am->mNumFaces; x++) {
            auto face = am->mFaces[x];
            for (unsigned int y = 0; y < face.mNumIndices; y++)
                this->indices->Add(face.mIndices[y]);
        }
        for (int index = 0; index < am->mNumVertices; ++index) {
            this->vertices->Add(am->mVertices[index].x);
            this->vertices->Add(am->mVertices[index].y);
            this->vertices->Add(am->mVertices[index].z);

            if (am->HasNormals()) {
                this->normals->Add(am->mNormals[index].x);
                this->normals->Add(am->mNormals[index].y);
                this->normals->Add(am->mNormals[index].z);
            }

            if (am->HasTangentsAndBitangents()) {
                this->tangents->Add(am->mTangents[index].x);
                this->tangents->Add(am->mTangents[index].y);
                this->tangents->Add(am->mTangents[index].z);
            }

            if (am->mColors[0]) {
                this->colors->Add(am->mColors[0][index].r);
                this->colors->Add(am->mColors[0][index].g);
                this->colors->Add(am->mColors[0][index].b);
                this->colors->Add(am->mColors[0][index].a);
            }

            if (am->mTextureCoords[0]) {
                this->uv0s->Add(am->mTextureCoords[0][index].x);
                this->uv0s->Add(am->mTextureCoords[0][index].y);
            }
            if (am->mTextureCoords[1]) {
                this->uv0s->Add(am->mTextureCoords[1][index].x);
                this->uv0s->Add(am->mTextureCoords[1][index].y);
            }
            if (am->mTextureCoords[2]) {
                this->uv0s->Add(am->mTextureCoords[2][index].x);
                this->uv0s->Add(am->mTextureCoords[2][index].y);
            }
        }
    });
    this->memorySize = 0;
    this->memorySize += this->vertices->MemorySize();
    this->memorySize += this->normals->MemorySize();
    this->memorySize += this->tangents->MemorySize();
    this->memorySize += this->colors->MemorySize();
    this->memorySize += this->uv0s->MemorySize();
    this->memorySize += this->uv1s->MemorySize();
    this->memorySize += this->uv2s->MemorySize();
    if (this->normals->Size() < 1)
        this->normals = nullptr;
    if (this->tangents->Size() < 1)
        this->tangents = nullptr;
    if (this->colors->Size() < 1)
        this->colors = nullptr;
    if (this->uv0s->Size() < 1)
        this->uv0s = nullptr;
    if (this->uv1s->Size() < 1)
        this->uv1s = nullptr;
    if (this->uv2s->Size() < 1)
        this->uv2s = nullptr;
}
