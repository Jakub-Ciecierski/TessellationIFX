#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include <stdexcept>
#include <shaders/program.h>
#include <render_object.h>
#include <render_object_loader.h>
#include <camera.h>
#include <lighting/light_source.h>
#include <light_loader.h>
#include <lighting/light_group.h>
#include <mesh/patch/patch.h>
#include "camera_controls.h"
#include "window.h"
#include "shaders/loaders/program_loader.h"

using namespace std;

// ------------------------------

float lastTick;

int width;
int height;

ifc::Window* window;

Camera* camera;
CameraControls * controls;

RenderObjectLoader* renderObjectLoader;
RenderObject* squareObjectLight1;

RenderObject* patchObject;
RenderObject* bezierPatchObject;
RenderObject* bezierBowlPatchObject;
RenderObject* bezierAsymmetricPatchObject;

LightLoader lightLoader;
LightGroup lightGroup;
LightPoint* lightPoint1;
LightDirectional* lightDirectional;
LightSpotlight* lightSpotlight;

ProgramLoader programLoader;
Program* programBumpMap;
Program* programLight;
Program* programLamp;
Program* programTess;
Program* programTessBezier;


// ------------------------------

void initContext();
void initRenderContext();
void initOpenGLContext();
void initCallbacks();

void initScene();
void initExampleMeshes();
void initShaders();

void releaseResources();

void key_callback(GLFWwindow* window, int key,
                  int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window,
                           int button, int action, int mods);
void mousescroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void mainLoop();

void update();
void render();

// ------------------------------

int main() {
    initContext();
    initScene();

    mainLoop();

    releaseResources();

    return 0;
}
void initContext(){
    initRenderContext();

    width = 800;
    height = 600;
    window = new ifc::Window(width, height, "Duck");

    initOpenGLContext();
    initCallbacks();
}

void initRenderContext(){
    glfwInit();
    // OpenGL version required
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    // No legacy functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void initOpenGLContext(){
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK){
        throw new std::invalid_argument("Failed to initialize GLEW");
    }
}

void initCallbacks(){
    glfwSetKeyCallback(window->getHandle(), key_callback);
    glfwSetCursorPosCallback(window->getHandle(), mouse_callback);
    glfwSetMouseButtonCallback(window->getHandle(), mouse_button_callback);
    glfwSetScrollCallback(window->getHandle(), mousescroll_callback);
}


void initScene(){
    camera = new Camera(&width, &height);
    camera->moveTo(glm::vec3(-1.5f, 0.8f, 0.0f));

    controls = new CameraControls(camera);

    initShaders();
    initExampleMeshes();

    lastTick = glfwGetTime();
}

void initExampleMeshes(){
    renderObjectLoader = new RenderObjectLoader();
    squareObjectLight1 = renderObjectLoader->loadLampObject();
    patchObject = renderObjectLoader->loadSquareObject();
    bezierPatchObject = renderObjectLoader->loadBicubicBezierPatchObject();
    bezierBowlPatchObject
            = renderObjectLoader->loadBicubicBezierBowlPatchObject();
    bezierAsymmetricPatchObject
            = renderObjectLoader->loadBicubicBezierAsymmetricPatchObject();

    // ------

    lightPoint1 = lightLoader.loadPointLight();
    lightDirectional = lightLoader.loadDirLight();
    lightSpotlight = lightLoader.loadSpotlight();
    lightPoint1->setRenderObject(squareObjectLight1);
    lightSpotlight->setCamera(camera);
    // -------

    lightGroup.addLightDirectional(lightDirectional);
    lightGroup.addLightSpotlight(lightSpotlight);
    lightGroup.addLightPoint(lightPoint1);
    // -------

    squareObjectLight1->scale(glm::vec3(0.3f, 0.3f, 0.3f));

    squareObjectLight1->moveTo(glm::vec3(0.0f, 5.0f, 0.0f));
}

void initShaders(){
    programBumpMap = programLoader.loadBumpMappingProgram();
    programLight = programLoader.loadAllLightProgram();
    programLamp = programLoader.loadLampProgram();
    programTess = programLoader.loadTessellationProgram();
    programTessBezier = programLoader.loadTessellationBicubicBezierProgram();
}

void releaseResources(){
    delete window;

    delete programBumpMap;
    delete programLight;
    delete programLamp;
    delete programTess;

    delete renderObjectLoader;
    delete squareObjectLight1;
    delete patchObject;
    delete bezierPatchObject;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    controls->onKeyboardAction(action, key);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    controls->onMouseAction(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window,
                           int button, int action, int mods){
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    if(state == GLFW_PRESS){
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        controls->setMousePress(true);
        controls->setPressedPosition(xpos, ypos);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }else if(state == GLFW_RELEASE){
        controls->setMousePress(false);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void mousescroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    Patch* patch = static_cast<Patch*>(patchObject->getModel()->getMesh(0));
    Patch* bezierPatch
            = static_cast<Patch*>(bezierPatchObject->getModel()->getMesh(0));
    Patch* bezierBowlPatch
            = static_cast<Patch*>
            (bezierBowlPatchObject->getModel()->getMesh(0));
    Patch* bezierAsymPatch
            = static_cast<Patch*>
            (bezierAsymmetricPatchObject->getModel()->getMesh(0));

    if(controls->isKeyPress(GLFW_KEY_LEFT_SHIFT)){
        patch->addToTessLevelOuter(yoffset);
        bezierPatch->addToTessLevelOuter(yoffset);
        bezierBowlPatch->addToTessLevelOuter(yoffset);
        bezierAsymPatch->addToTessLevelOuter(yoffset);
    }else{
        patch->addToTessLevelInner(yoffset);
        bezierPatch->addToTessLevelInner(yoffset);
        bezierBowlPatch->addToTessLevelInner(yoffset);
        bezierAsymPatch->addToTessLevelInner(yoffset);
    };
}

void update(){
    window->update();

    controls->doMovement();
    camera->update();

    squareObjectLight1->update();
    patchObject->update();
    bezierPatchObject->update();
    bezierBowlPatchObject->update();
    bezierAsymmetricPatchObject->update();

    // MOVE LIGHT ------------------
    static float a = 0;
    float radius = 4.0f;
    squareObjectLight1->moveTo(glm::vec3(cos(a)*radius,
                                         sin(a)*radius, 0.0f));
    a+=0.005f;
    if(a > 360) a = 0;
    // ------------------
}

void render(){
    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Program* program = programLight;
    camera->use(*program);
    lightGroup.use(*program);

    camera->use(*programTess);
    patchObject->render(*programTess);

    camera->use(*programTessBezier);
    bezierPatchObject->render(*programTessBezier);
    bezierBowlPatchObject->render(*programTessBezier);
    bezierAsymmetricPatchObject->render(*programTessBezier);

    // Draw Lamp
    camera->use(*programLamp);
    lightGroup.render(*programLamp);
}

void mainLoop(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while(!window->shouldClose())
    {
        update();
        render();

        glfwSwapBuffers(window->getHandle());
    }
    glfwTerminate();
}