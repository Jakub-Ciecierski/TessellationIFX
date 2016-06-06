//
// Created by jakub on 5/26/16.
//

#ifndef DUCK_RENDER_OBJECT_LOADER_H
#define DUCK_RENDER_OBJECT_LOADER_H


#include <mesh/loaders/mesh_loader.h>
#include <render_object.h>
#include <mesh/model.h>

/*
 * Loads meshes using MeshLoader and creates render objects.
 * Must be created after rendering context is ready.
 */
class RenderObjectLoader {
private:

    Model* nanosuitModel;
    Model* squareModel;
    Model* cubeModel;
    Model* cubeMapModel;
    Model* lampModel;
    Model* bicubicBezierPatchModel;
    Model* bicubicBezierBowlPatchModel;
    Model* bicubicBezierAsymmetricPatchModel;

    void initModels();

public:

    RenderObjectLoader();

    ~RenderObjectLoader();

    RenderObject* loadBicubicBezierPatchObject();
    RenderObject* loadBicubicBezierBowlPatchObject();
    RenderObject* loadBicubicBezierAsymmetricPatchObject();

    RenderObject* loadSquareObject();
    RenderObject* loadCubeObject();
    RenderObject* loadCubemapObject();
    RenderObject* loadLampObject();
    RenderObject* loadnanosuitObject();
};


#endif //DUCK_RENDER_OBJECT_LOADER_H
