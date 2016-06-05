//
// Created by jakub on 5/24/16.
//

#include "fragment_shader.h"

using namespace std;

FragmentShader::FragmentShader(string shaderSource) :
        Shader(shaderSource){

}

FragmentShader::~FragmentShader() {

}

GLuint FragmentShader::createShader() {
    return glCreateShader(GL_FRAGMENT_SHADER);
}

