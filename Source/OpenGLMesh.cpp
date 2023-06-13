//
// Created by MisThe on 2023/6/11.
//

#include <glad/glad.h>
#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLMesh.h"

void OpenGLMesh::CustomMark() {

}

OpenGLMesh::OpenGLMesh(Mesh *mesh) {
    unsigned int vbo, ebo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh->Size(), nullptr, GL_STATIC_DRAW);

    int offset = 0;
    offset += this->SubVertexBuffer(offset, mesh->vertices);
    offset += this->SubVertexBuffer(offset, mesh->normals);
    offset += this->SubVertexBuffer(offset, mesh->tangents);
    offset += this->SubVertexBuffer(offset, mesh->colors);
    offset += this->SubVertexBuffer(offset, mesh->uv0s);
    offset += this->SubVertexBuffer(offset, mesh->uv1s);
    offset += this->SubVertexBuffer(offset, mesh->uv2s);
    if (offset < 1)
        return;

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices->MemorySize(), mesh->indices->Begin(), GL_STATIC_DRAW);

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

void OpenGLMesh::Bind() const {
    glBindVertexArray(this->vao);
}

OpenGLMesh::~OpenGLMesh() {
    glDeleteVertexArrays(1, &this->vao);
}

int OpenGLMesh::SubVertexBuffer(int offset, Vector<float> *buffer) {
    if (buffer == nullptr)
        return 0;
    int size = buffer->MemorySize();
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, buffer->Begin());
    return size;
}
