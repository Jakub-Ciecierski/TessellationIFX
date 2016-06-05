//
// Created by jakub on 5/23/16.
//

#ifndef DUCK_OBJECT_H
#define DUCK_OBJECT_H

#include <string>
#include "object_id.h"

class Object {
private:

    ObjectID id;
    std::string name;

public:

    Object(ObjectID id, std::string name);

    virtual ~Object();

};


#endif //DUCK_OBJECT_H
