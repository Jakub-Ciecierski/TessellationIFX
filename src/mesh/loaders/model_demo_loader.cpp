//
// Created by jakub on 5/28/16.
//

#include <mesh/loaders/model_loader.h>
#include <mesh/loaders/mesh_loader.h>
#include "model_demo_loader.h"

ModelDemoLoader::ModelDemoLoader(){

}

ModelDemoLoader::~ModelDemoLoader() {

}

Model ModelDemoLoader::LoadNanoSuitModel() {
    std::string path = "res/models/nanosuit/nanosuit.obj";

    //ModelLoader loader(path);
    //return loader.loadModel();

    return ModelDemoLoader::LoadCubeModel();
}

Model ModelDemoLoader::LoadSquareModel() {
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadPatch();
    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}

Model ModelDemoLoader::LoadCubeModel() {
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadCube();
    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}

Model ModelDemoLoader::LoadCubemapModel(){
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadCubemap();
    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}

Model ModelDemoLoader::LoadLampModel() {
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadLamp();
    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}