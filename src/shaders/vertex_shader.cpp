//
// Created by jakub on 5/24/16.
//

#include "vertex_shader.h"

using namespace std;

VertexShader::VertexShader(string shaderSource) :
        Shader(shaderSource){

}

VertexShader::~VertexShader() {

}

GLuint VertexShader::createShader() {
    return glCreateShader(GL_VERTEX_SHADER);
}
