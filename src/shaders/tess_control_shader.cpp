//
// Created by jakub on 6/5/16.
//

#include "tess_control_shader.h"

TessControlShader::TessControlShader(std::string shaderSource) :
    Shader(shaderSource){

}

TessControlShader::~TessControlShader() {

}

GLuint TessControlShader::createShader() {
    return glCreateShader(GL_TESS_CONTROL_SHADER);
}
