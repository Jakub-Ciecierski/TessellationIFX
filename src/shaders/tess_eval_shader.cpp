//
// Created by jakub on 6/5/16.
//

#include "tess_eval_shader.h"

TessEvalShader::TessEvalShader(std::string shaderSource) :
        Shader(shaderSource){

}

TessEvalShader::~TessEvalShader() {

}

GLuint TessEvalShader::createShader() {
    return glCreateShader(GL_TESS_EVALUATION_SHADER);
}
