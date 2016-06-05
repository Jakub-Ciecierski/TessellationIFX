//
// Created by jakub on 5/27/16.
//

#ifndef DUCK_LIGHT_GLOBAL_H
#define DUCK_LIGHT_GLOBAL_H


#include "light_source.h"

/*
 * Global Light simply binds the position with the shader.
 */
class LightPoint : public LightSource{
protected:
    virtual void bind(const Program& program, int id = -1) override ;

public:

    LightPoint();

    LightPoint(RenderObject *renderObject);

    ~LightPoint();



};


#endif //DUCK_LIGHT_GLOBAL_H
