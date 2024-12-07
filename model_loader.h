#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class ModelLoader {
public:
    // 加载模型
    static void loadModel(const std::string& path);
    
    // 渲染模型
    static void renderModel();

private:
    static std::vector<glm::vec3> vertices;
    static std::vector<glm::vec2> textures;
    static std::vector<glm::vec3> normals;

    static void processNode(aiNode* node, const aiScene* scene);
    static void processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif // MODEL_LOADER_H
