//
// Created by jakub on 5/28/16.
//

#include <mesh/loaders/model_loader.h>
#include <mesh/loaders/mesh_loader.h>
#include <textures/texture_loader.h>
#include <mesh/patch/patch.h>
#include "model_demo_loader.h"

using namespace glm;
using namespace std;

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

Model ModelDemoLoader::LoadBicubicBezierSurfaceC0() {
    MeshLoader meshLoader;
    Mesh* mesh1 = meshLoader.LoadBicubicBezierPatch(-1, 1, 1.5f);
    Mesh* mesh2 = meshLoader.LoadBicubicBezierPatch(1, 1, -1.5f);
    Mesh* mesh3 = meshLoader.LoadBicubicBezierPatch(3, 1, 1.5f);

    Mesh* mesh4 = meshLoader.LoadBicubicBezierPatch(-1, -1, -1.5f);
    Mesh* mesh5 = meshLoader.LoadBicubicBezierPatch(1, -1, 1.5f);
    Mesh* mesh6 = meshLoader.LoadBicubicBezierPatch(3, -1, -1.5f);

    std::vector<Mesh*> meshes = {mesh1, mesh2, mesh3,
                                 mesh4, mesh5, mesh6};

    return Model(meshes);
}

Model ModelDemoLoader::LoadBicubicBezierPatch() {
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadBicubicBezierPatch(-1, 1, 1.5f);

    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}

Model ModelDemoLoader::LoadBicubicBezierBowlPatch() {
    MeshLoader meshLoader;

    Mesh* mesh = meshLoader.LoadBicubicBezierPatch(-1, 1, -1.5f);

    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
}

Model ModelDemoLoader::LoadBicubicBezierAsymmetricPatch() {
    MeshLoader meshLoader;
    Mesh* mesh = meshLoader.LoadBicubicBezierAsymmetricPatch();

    std::vector<Mesh*> meshes = {mesh};

    return Model(meshes);
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