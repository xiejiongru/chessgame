#include "model_loader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

std::vector<glm::vec3> ModelLoader::vertices;
std::vector<glm::vec2> ModelLoader::textures;
std::vector<glm::vec3> ModelLoader::normals;

void ModelLoader::loadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
        return;
    }

    processNode(scene->mRootNode, scene);
}

void ModelLoader::processNode(aiNode* node, const aiScene* scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        processMesh(mesh, scene);
    }

    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], scene);
    }
}

void ModelLoader::processMesh(aiMesh* mesh, const aiScene* scene) {
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        glm::vec3 vertex(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        vertices.push_back(vertex);

        glm::vec2 texture(0.0f, 0.0f);
        if (mesh->mTextureCoords[0]) {
            texture.x = mesh->mTextureCoords[0][i].x;
            texture.y = mesh->mTextureCoords[0][i].y;
        }
        textures.push_back(texture);

        glm::vec3 normal(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        normals.push_back(normal);
    }
}

void ModelLoader::renderModel() {
    for (const auto& vertex : vertices) {
        // 渲染模型顶点
    }
}
