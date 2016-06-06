//
// Created by jakub on 6/5/16.
//

#include <shaders/program.h>
#include <mesh/patch/patch.h>

Patch::Patch(std::vector<Vertex> vertices,
             std::vector <GLuint>& indices,
             std::vector<Texture>& textures,
             float tessLevelInner,
             float tessLevelOuter,
             int vertexCountPerPatch) :
        Mesh(vertices, indices, textures,
             GL_LINES, GL_PATCHES),
        tessLevelInner(tessLevelInner), tessLevelOuter(tessLevelOuter),
        vertexCountPerPatch(vertexCountPerPatch){

}

Patch::Patch(std::vector<Vertex> vertices,
             std::vector <GLuint>& indices,
             std::vector<Texture>& textures,
             Material material,
             float tessLevelInner,
             float tessLevelOuter,
             int vertexCountPerPatch) :
        Mesh(vertices, indices, textures,
             material, GL_LINES, GL_PATCHES),
        tessLevelInner(tessLevelInner), tessLevelOuter(tessLevelOuter),
        vertexCountPerPatch(vertexCountPerPatch){

}

Patch::~Patch() {

}

void Patch::bindTessLevel(const Program& program) {
    GLint tessInnerLoc
            = glGetUniformLocation(program.getID(),
                                   TESSELLATION_LVL_INNER_NAME.c_str());

    GLint tessOuterLoc
            = glGetUniformLocation(program.getID(),
                                   TESSELLATION_LVL_OUTER_NAME.c_str());

    glUniform1f(tessInnerLoc, this->tessLevelInner);
    glUniform1f(tessOuterLoc, this->tessLevelOuter);
}


void Patch::draw(const Program &program) {
    bindTessLevel(program);
    // TODO should be called once
    glPatchParameteri(GL_PATCH_VERTICES, vertexCountPerPatch);

    this->drawingMode = GL_PATCHES;

    Mesh::draw(program);
}

void Patch::addToTessLevelInner(float lvl){
    tessLevelInner += lvl;
    if(tessLevelInner < 1){
        tessLevelInner = 1;
    }
}

void Patch::addToTessLevelOuter(float lvl){
    tessLevelOuter += lvl;
    if(tessLevelOuter < 1){
        tessLevelOuter = 1;
    }
}

void Patch::setTessLevelInner(float lvl) {
    this->tessLevelInner = lvl;
}

void Patch::setTessLevelOuter(float lvl) {
    this->tessLevelOuter = lvl;
}
