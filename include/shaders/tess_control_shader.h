//
// Created by jakub on 6/5/16.
//

#ifndef TESELATION_TESS_CONTROL_SHADER_H
#define TESELATION_TESS_CONTROL_SHADER_H

#include <shaders/shader.h>

class TessControlShader : public Shader {
private:

protected:
    virtual GLuint createShader() override;

public:

    TessControlShader(std::string shaderSource);

    ~TessControlShader();

};


#endif //TESELATION_TESS_CONTROL_SHADER_H
