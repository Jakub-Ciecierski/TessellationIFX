//
// Created by jakub on 5/24/16.
//

#ifndef DUCK_FRAGMENT_SHADER_H
#define DUCK_FRAGMENT_SHADER_H

#include "shader.h"

class FragmentShader : public Shader{
private:

protected:
    virtual GLuint createShader();

public:
    FragmentShader(std::string shaderSource);

    ~FragmentShader();

};


#endif //DUCK_FRAGMENT_SHADER_H
