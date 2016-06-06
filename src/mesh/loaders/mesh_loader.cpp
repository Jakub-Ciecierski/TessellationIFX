//
// Created by jakub on 5/24/16.
//
#include <iostream>

#include "mesh_loader.h"
#include <textures/texture_loader.h>
#include <mesh/patch/patch.h>

using namespace std;
using namespace glm;

MeshLoader::MeshLoader(){

}

MeshLoader::~MeshLoader() {

}

Mesh* MeshLoader::LoadBicubicBezierPatch(){
    float end   = -1.0f;
    float start = 1.0f;
    float mid1  = -0.33f;
    float mid2  = 0.33f;

    float depth = 1.5f;

    vector<Vertex> vertices = {
            // Row1
            Vertex{vec3(end,  start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 2
            Vertex{vec3(end,  mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 3
            Vertex{vec3(end,  mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 4
            Vertex{vec3(end,  end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)}
    };

    // Indices for Patch
    vector<GLuint> indices = {
            0, 1, 2, 3,
            4, 5, 6, 7,
            8, 9, 10, 11,
            12, 13, 14, 15
    };

    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadDynamicBlueDiffuseTexture();
    Texture textureSpecular = textureLoader.LoadDynamicBlueSpecularTexture();

    std::vector<Texture> textures = {textureDiffuse, textureSpecular};

    Mesh* mesh = new Patch(vertices, indices, textures,
                           2.0f, 2.0f, vertices.size() );
    mesh->setPolygonMode(GL_LINE);

    Material material;
    material.shininess = 332.0f;

    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadBicubicBezierBowlPatch(){
    float end   = -1.0f;
    float start = 1.0f;
    float mid1  = -0.33f;
    float mid2  = 0.33f;

    float depth = -1.5f;

    vector<Vertex> vertices = {
            // Row1
            Vertex{vec3(end,  start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 2
            Vertex{vec3(end,  mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 3
            Vertex{vec3(end,  mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 4
            Vertex{vec3(end,  end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)}
    };

    // Indices for Patch
    vector<GLuint> indices = {
            0, 1, 2, 3,
            4, 5, 6, 7,
            8, 9, 10, 11,
            12, 13, 14, 15
    };

    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadDynamicBlueDiffuseTexture();
    Texture textureSpecular = textureLoader.LoadDynamicBlueSpecularTexture();

    std::vector<Texture> textures = {textureDiffuse, textureSpecular};

    Mesh* mesh = new Patch(vertices, indices, textures,
                           2.0f, 2.0f, vertices.size() );
    mesh->setPolygonMode(GL_LINE);

    Material material;
    material.shininess = 332.0f;

    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadBicubicBezierAsymmetricPatch(){
    float end   = -1.0f;
    float start = 1.0f;
    float mid1  = -0.33f;
    float mid2  = 0.33f;

    float depth = 0.0f;
    float depth1 = -1.0f;
    float depth2 = 1.0f;

    vector<Vertex> vertices = {
            // Row1
            Vertex{vec3(end,  start, depth1),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, start, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, start, depth2),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 2
            Vertex{vec3(end,  mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid2, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid2, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 3
            Vertex{vec3(end,  mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, mid1, depth),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, mid1, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},

            // Row 4
            Vertex{vec3(end,  end, depth2),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(mid1, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(mid2, end, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(start, end, depth1),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)}
    };

    // Indices for Patch
    vector<GLuint> indices = {
            0, 1, 2, 3,
            4, 5, 6, 7,
            8, 9, 10, 11,
            12, 13, 14, 15
    };

    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadDynamicBlueDiffuseTexture();
    Texture textureSpecular = textureLoader.LoadDynamicBlueSpecularTexture();

    std::vector<Texture> textures = {textureDiffuse, textureSpecular};

    Mesh* mesh = new Patch(vertices, indices, textures,
                           2.0f, 2.0f, vertices.size() );
    mesh->setPolygonMode(GL_LINE);

    Material material;
    material.shininess = 332.0f;

    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadPatch(){
    // Position, Normal, TexCoord
    vector<Vertex> vertices = {
            // Front

            Vertex{vec3(0.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            Vertex{vec3(1.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},

            Vertex{vec3(1.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},

            Vertex{vec3(0.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)}
    };

    // Indices for Patch
    vector<GLuint> indices = {
            0, 1, 2, 3
    };

    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadDynamicBlueDiffuseTexture();
    Texture textureSpecular = textureLoader.LoadDynamicBlueSpecularTexture();

    std::vector<Texture> textures = {textureDiffuse, textureSpecular};

    Mesh* mesh = new Patch(vertices, indices, textures);
    mesh->setPolygonMode(GL_LINE);

    Material material;
    material.shininess = 32.0f;
    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadCubemap(){
    // Position, Normal, TexCoord
    vector<Vertex> vertices = {
            // Front
            Vertex{vec3(1.0f,  1.0f, -1.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f,  -1.0f, -1.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(-1.0f,  -1.0f, -1.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(-1.0f,  1.0f, -1.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            // Back
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, -1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(-1.0f, -1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(-1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)},

            // Left
            Vertex{vec3(-1.0f, 1.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(-1.0f, -1.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(-1.0f, -1.0f, -1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(-1.0f, 1.0f, -1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Right
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, -1.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(1.0f, -1.0f, -1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(1.0f, 1.0f, -1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Bottom
            Vertex{vec3(1.0f, -1.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, -1.0f, -1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(-1.0f, -1.0f, -1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(-1.0f, -1.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Top
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 1.0f, -1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(-1.0f, 1.0f, -1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(-1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f)},
    };

    vector<GLuint> indices = {
            3, 1, 0,    3, 2, 1,            // front
            4, 5, 7,    5, 6, 7,            // back

            8, 9, 11,    9, 10, 11,           // left
            15, 13, 12,    15, 14, 13,        // right

            16, 17, 19,    17, 18, 19,        // bottom
            23, 21, 20,    23, 22, 21,        // top
    };
    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadExampleCubemap();

    std::vector<Texture> textures = {textureDiffuse};

    Mesh* mesh = new Mesh(vertices, indices, textures);

    Material material;
    material.shininess = 32.0f;
    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadCube(){
    // Position, Normal, TexCoord
    vector<Vertex> vertices = {
            // Front
            Vertex{vec3(1.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            // Back
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)},

            // Left
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(0.0f, 0.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 0.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 0.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Right
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(1.0f, 0.0f, 0.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(1.0f, 1.0f, 0.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Bottom
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 0.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 0.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Top
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 1.0f, 0.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 0.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f)},
    };

    vector<GLuint> indices = {
            0, 1, 3,    1, 2, 3,            // front
            7, 5, 4,    5, 6, 7,            // back
            8, 9, 11,    9, 10, 11,           // left
            12, 13, 15,    13, 14, 15,        // right
            16, 17, 19,    17, 18, 19,        // bottom
            20, 21, 23,    21, 22, 23,        // top
    };
    TextureLoader textureLoader;
    Texture textureDiffuse = textureLoader.LoadContainerDiffuse();
    Texture textureSpecular = textureLoader.LoadContainerSpecular();

    std::vector<Texture> textures = {textureDiffuse, textureSpecular};

    Mesh* mesh = new Mesh(vertices, indices, textures, GL_TRIANGLES);

    Material material;
    material.shininess = 32.0f;
    mesh->setMaterial(material);

    return mesh;
}

Mesh* MeshLoader::LoadLamp(){
    vector<Vertex> vertices = {
            // Front
            Vertex{vec3(1.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f,  0.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f,  1.0f, 0.0f),
                   vec3(0.0f, 0.0f, -1.0f), vec2(0.0f, 1.0f)},

            // Back
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)},

            // Left
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(0.0f, 0.0f, 1.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 0.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 0.0f),
                   vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Right
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(1.0f, 0.0f, 0.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(1.0f, 1.0f, 0.0f),
                   vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Bottom
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 0.0f, 0.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 0.0f, 0.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(1.0f, 0.0f, 1.0f),
                   vec3(0.0f, -1.0f, 0.0f), vec2(0.0f, 1.0f)},

            // Top
            Vertex{vec3(1.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)},
            Vertex{vec3(1.0f, 1.0f, 0.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 0.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
            Vertex{vec3(0.0f, 1.0f, 1.0f),
                   vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f)},
    };
    vector<GLuint> indices = {
            0, 1, 3,    1, 2, 3,            // front
            7, 5, 4,    5, 6, 7,            // back
            8, 9, 11,    9, 10, 11,           // left
            12, 13, 15,    13, 14, 15,        // right
            16, 17, 19,    17, 18, 19,        // bottom
            20, 21, 23,    21, 22, 23,        // top
    };
    TextureLoader textureLoader;

    std::vector<Texture> textures;

    return new Mesh(vertices, indices, textures, GL_TRIANGLES);
}