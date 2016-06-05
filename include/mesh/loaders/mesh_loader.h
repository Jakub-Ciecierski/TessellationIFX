//
// Created by jakub on 5/24/16.
//

#ifndef DUCK_MESH_LOADER_H
#define DUCK_MESH_LOADER_H

#include "mesh.h"

/*
 * Loads specific meshes to the system
 */
class MeshLoader {
private:
    //static void Calculate
public:

    MeshLoader();

    ~MeshLoader();

    static Mesh* LoadPatch();
    static Mesh* LoadCubemap();
    static Mesh* LoadCube();
    static Mesh* LoadLamp();

};


#endif //DUCK_MESH_LOADER_H
