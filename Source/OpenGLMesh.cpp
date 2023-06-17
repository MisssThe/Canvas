//
// Created by MisThe on 2023/6/11.
//

#include <glad/glad.h>
#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLMesh.h"

void OpenGLMesh::CustomMark() {

}

OpenGLMesh::OpenGLMesh(Mesh *mesh) {
    this->CompileMesh(mesh);
}

OpenGLMesh::~OpenGLMesh() {
    glDeleteVertexArrays(1, &this->vao);
}

bool OpenGLMesh::CompileMesh(Mesh *mesh) {
    unsigned int vbo, ebo;
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices->MemorySize(), mesh->indices->Begin(), GL_STATIC_DRAW);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh->Size(), nullptr, GL_STATIC_DRAW);

    int offset = 0;
    offset += this->SubVertexBuffer(offset, mesh->vertices, 0, 3);
    offset += this->SubVertexBuffer(offset, mesh->normals, 1, 3);
    offset += this->SubVertexBuffer(offset, mesh->tangents, 2, 4);
    offset += this->SubVertexBuffer(offset, mesh->colors, 3, 4);
    offset += this->SubVertexBuffer(offset, mesh->uv0s, 4, 2);
    offset += this->SubVertexBuffer(offset, mesh->uv1s, 5, 2);
    offset += this->SubVertexBuffer(offset, mesh->uv2s, 6, 2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    if (offset < 1) {
        glDeleteVertexArrays(1, &this->vao);
        this->vao = 0;
        return false;
    }
    return true;
}

void OpenGLMesh::Bind() const {
    if (this->vao < 1)
        return;
    glBindVertexArray(this->vao);
}

int OpenGLMesh::SubVertexBuffer(long long int offset, Vector<float> *buffer, int index, int stride) {
    if (buffer == nullptr)
        return 0;
    int size = buffer->MemorySize();
    glBufferSubData(GL_ARRAY_BUFFER,offset,size,buffer->Begin());
    glVertexAttribPointer(index, stride, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void *) offset);
    glEnableVertexAttribArray(index);
    return size;
}
