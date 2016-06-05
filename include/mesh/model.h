//
// Created by jakub on 5/28/16.
//

#ifndef DUCK_MODEL_H
#define DUCK_MODEL_H

#include "mesh.h"
#include <ostream>

/*
 * Model class is an encapsulation of many meshes take up a single model
 */
class Model {
private:
    std::vector<Mesh*> meshes;

public:

    Model(const std::vector<Mesh*>& meshes);
    Model(const Model& other);

    ~Model();
    Mesh* getMesh(int i);

    void draw(const Program& program);

    std::string toString() const;
};

#endif //DUCK_MODEL_H
