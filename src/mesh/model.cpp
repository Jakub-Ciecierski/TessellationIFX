//
// Created by jakub on 5/28/16.
//

#include "model.h"

using namespace std;

Model::Model(const std::vector<Mesh*>& meshes) :
        meshes(meshes){

}

Model::Model(const Model& other){
    meshes = other.meshes;
}

Model::~Model() {
    for(unsigned int i = 0; i < meshes.size(); i++){
        delete meshes[0];
    }
}

const std::vector<Mesh*>& Model::getMeshes(){
    return this->meshes;
}

Mesh* Model::getMesh(int i){
    return meshes[i];
}

void Model::draw(const Program &program) {
    for(unsigned int i = 0; i < meshes.size(); i++){
        meshes[i]->draw(program);
    }
}

std::string Model::toString() const{
    std::string str = "";
    str += "Mesh count:  " + std::to_string(meshes.size()) + "\n";
    for(unsigned int i = 0; i < meshes.size(); i++){
        str += "Mesh[" + std::to_string(i) + "]" + "\n";
        str += meshes[i]->toString();
    }

    return str;
}