#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;

public:
    Camera(glm::vec3 pos, glm::vec3 tar, glm::vec3 upDir);
    glm::mat4 getViewMatrix();
};

#endif
