//
// Created by MisThe on 2023/6/11.
//

#include <glad/glad.h>
#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLMesh.h"

void OpenGLMesh::CustomMark() {

}

OpenGLMesh::OpenGLMesh(Mesh *mesh) {
    unsigned int vbo, ebo;
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices->MemorySize(), mesh->vertices->Begin(), GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices->MemorySize(), mesh->indices->Begin(), GL_STATIC_DRAW);

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
