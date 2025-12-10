#ifndef NEWTON_ENTITY_H
#define NEWTON_ENTITY_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <glm/vec2.hpp>

namespace newton {
  /**
   * @brief An entity class.
   * 
   * Is a physics body that can interact with other Entities through an Engine.
   */
  class Entity
  {
  private:
    /**
     * The current position of the Entity.
     */
    glm::vec2 m_pos;

    /**
     * The position of the Entity on the previous update cycle.
     */
    glm::vec2 m_prevPos;

    /**
     * The current velocity of the Entity.
     */
    glm::vec2 m_vel;

    /**
     * The orce that will be applied on the next update cycle.
     */
    glm::vec2 m_acc;

    /**
     * The maximum velocity of the Entity.
     */
    float m_maxVel;

    /**
     * The mass of the Entity.
     */
    float m_mass;

    /**
     * The width of the Entity.
     */
    const float m_w;

    /**
     * The height of the Entity.
     */
    const float m_h;

    /**
     * The "bounciness" of the Entity.
     */
    float m_restitution;

    /**
     * The friction of the Entity.
     */
    float m_friction;

    /**
     * Can the Entity be moved?
     */
    bool m_isStatic;

    /**
     * Is the Entity affected by gravity?
     */
    bool m_gravityAffected;

    /**
     * The priority of the Entity during collision checks. Higher = greater priority.
     */
    int m_collPriority;

    /**
     * The priority of the Entity during rendering. Higher = rendered first.
     */
    int m_displayPriority;

    /**
     * The tags of the Entity.
     */
    std::vector<std::string> m_labels;

    /**
     * What tags to avoid while doing collision checks.
     */
    std::vector<std::string> m_noColl;

  public:
    Entity(glm::vec2, float, float, float, float, float, float, bool, bool, int, int, std::vector<std::string>, std::vector<std::string>);
    void applyForce(glm::vec2);
    static bool checkCollide(Entity&, Entity&);
    static void entityCollide(Entity&, Entity&);
  };
}

#endif /*NEWTON_ENTITY_H*/