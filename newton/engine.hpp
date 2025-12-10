#ifndef NEWTON_ENGINE_H
#define NEWTON_ENGINE_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <glm/vec2.hpp>

#include "entity.hpp"

namespace newton {
  /**
   * @brief An action for an Engine to perform.
   * 
   * Contains an Entity for the Engine to operate on, and a type for what the Engine should do.
   */
  struct Action
  {
    /**
     * The Entity the Engine should operate on.
     */
    Entity entity;

    /**
     * What the Engine should do with the Entity.
     */
    std::string type;
  };

  /**
   * @brief An engine class.
   * 
   * Is an Engine that operates on Entities to run a simulation of a world filled with physics bodies.
   */
  class Engine
  {
  private:
    std::vector<Entity*> m_entities;    // The Entities within the Engine's world
    std::vector<Action> m_actionStack; // Special actions the Engine performs at the end of the next update cycle.
    glm::vec2 m_gravity;               // A constant force applied onto all Entities inside the Engine each update cycle.

  public:
    Engine();
    Engine(glm::vec2);
    std::vector<Entity*> getEntities();
    std::vector<Action> getActionStack();
    void setGravity(glm::vec2);
    glm::vec2 getGravity();
    void update();
    void addAction(Action&);
    void runActions();
    void clearActions();
    void addEntity(Entity&);
    void removeEntity(Entity&);
  };
}

#endif /*NEWTON_ENGINE_H*/