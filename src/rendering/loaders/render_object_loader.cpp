//
// Created by jakub on 5/26/16.
//

#include <mesh/loaders/model_demo_loader.h>
#include "render_object_loader.h"

RenderObjectLoader::RenderObjectLoader(){
    initModels();
}

RenderObjectLoader::~RenderObjectLoader() {
    delete nanosuitModel;
    delete cubeModel;
    delete cubeMapModel;
    delete lampModel;
}

void RenderObjectLoader::initModels() {
    squareModel = new Model(ModelDemoLoader::LoadSquareModel());
    nanosuitModel = new Model(ModelDemoLoader::LoadNanoSuitModel());
    cubeMapModel = new Model(ModelDemoLoader::LoadCubemapModel());
    cubeModel = new Model(ModelDemoLoader::LoadCubeModel());
    lampModel = new Model(ModelDemoLoader::LoadLampModel());
}

RenderObject *RenderObjectLoader::loadSquareObject() {
    RenderObject* renderObject
            = new RenderObject(ObjectID(0), "Square", squareModel);
    float scaleFactor = 4.0f;
    renderObject->scale(glm::vec3(scaleFactor, scaleFactor, scaleFactor));
    renderObject->rotateTo(glm::vec3(0, 90.0f, 0));

    return renderObject;
}

RenderObject *RenderObjectLoader::loadCubeObject() {
    RenderObject* renderObject
            = new RenderObject(ObjectID(0), "Cube", cubeModel);

    return renderObject;
}

RenderObject *RenderObjectLoader::loadCubemapObject() {
    RenderObject* renderObject
            = new RenderObject(ObjectID(0), "Cube", cubeMapModel);
    float scaleFactor = 10.0f;
    renderObject->scale(glm::vec3(scaleFactor,
                                  scaleFactor,
                                  scaleFactor));
    return renderObject;
}

RenderObject *RenderObjectLoader::loadLampObject() {
    RenderObject* renderObject
            = new RenderObject(ObjectID(0), "Lamp", lampModel);

    return renderObject;
}

RenderObject* RenderObjectLoader::loadnanosuitObject(){
    RenderObject* renderObject
            = new RenderObject(ObjectID(0), "NanoSuit", nanosuitModel);
    float scaleFactor = 0.005f;
    renderObject->scale(glm::vec3(scaleFactor, scaleFactor, scaleFactor));

    return renderObject;
}