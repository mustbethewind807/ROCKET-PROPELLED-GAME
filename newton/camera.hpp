#ifndef NEWTON_CAMERA_H
#define NEWTON_CAMERA_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <glm/vec2.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "entity.hpp"
#include "engine.hpp"

namespace newton {
  /**
   * @brief A camera class.
   * 
   * Is an object that is able to render Entities inside an Engine onto the screen.
   */
  class Camera
  {
  private:
    /**
     * The current position of the Camera.
     */
    glm::vec2 m_pos;

    /**
     * Is the Camera linked to an active Entity?
     */
    bool m_linked;

    /**
     * The Entity the Camera is linked to.
     */
    Entity *m_linkedObject;

    /**
     * How fast should the Camera move? 0 means the Camera does not move, while 1 means the Camera always snaps to the position of the linked Entity.
     */
    float m_lerpSpeed;

  public:
    /**
     * A default Entity Cameras automatically link to when they do not have a specified Entity to link to.
     * Will make a const later once I think of a good default.
     */
    static Entity *defaultLinkEntity;

    Camera();
    void link(Entity&);
    void unlink();
    void update();
    void render(Engine&, GLFWwindow*);
  };
}

#endif /* NEWTON_CAMERA_H*/
