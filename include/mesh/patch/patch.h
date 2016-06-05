//
// Created by jakub on 6/5/16.
//

#ifndef TESELATION_PATCH_H
#define TESELATION_PATCH_H

#include <mesh/mesh.h>

class Patch : public Mesh{
private:
    float tessLevelInner;
    float tessLevelOuter;

    void bindTessLevel(const Program& program);

public:
    Patch(std::vector<Vertex> vertices,
          std::vector <GLuint>& indices,
          std::vector<Texture>& textures,
          float tessLevelInner = 3.0,
          float tessLevelOuter = 3.0);

    Patch(std::vector<Vertex> vertices,
          std::vector <GLuint>& indices,
          std::vector<Texture>& textures,
          Material material,
          float tessLevelInner = 3.0,
          float tessLevelOuter = 3.0);

    ~Patch();

    virtual void draw(const Program& program) override;

    void addToTessLevelInner(float lvl);
    void addToTessLevelOuter(float lvl);

    void setTessLevelInner(float lvl);
    void setTessLevelOuter(float lvl);
};


#endif //TESELATION_PATCH_H
