//
// Created by MisThe on 2023/6/11.
//

#ifndef CANVAS_1_0_OPENGLMESH_H
#define CANVAS_1_0_OPENGLMESH_H


#include "../../../../Framework/CustomPtr.h"
#include "../../Elements/Mesh.h"

class OpenGLMesh : public CustomPtr {
protected:
    void CustomMark() override;
    ~OpenGLMesh() override;
public:
    explicit OpenGLMesh(Mesh* mesh);
    void Bind() const;
    int Count() const;
private:
    int SubVertexBuffer(long long int offset, Vector<float>* buffer,int index, int stride);
    bool CompileMesh(Mesh *mesh);
private:
    unsigned int vao;
    int count;
};


#endif //CANVAS_1_0_OPENGLMESH_H
