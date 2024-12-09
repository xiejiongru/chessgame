#include "camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 tar, glm::vec3 upDir)
    : position(pos), target(tar), up(upDir) {}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, target, up);
}
