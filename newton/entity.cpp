#include "entity.hpp"

/**
 * @brief Constructs an Entity with every variable manually inputted.
 * 
 * @param pos the position of the Entity.
 * @param maxVel the maximum velocity of the Entity.
 * @param mass the mass of the Entity.
 * @param w the width of the Entity.
 * @param h the height of the Entity.
 * @param restitution the "bounciness" of the Entity. Should be between 0.0 and 1.0.
 * @param friction the friction of the Entity. Should be between 0.0 and 1.0.
 * @param isStatic is the Entity static?
 * @param gravityAffected is the Entity affected by gravity?
 * @param collPriority the priority of the Entity during collision checks.
 * @param displayPriority the priority of the Entity during rendering.
 * @param labels the labels/tags given to the Entity.
 * @param noColl the labels the Entity avoids during collision checks. Basically collision masking.
 * 
 * @returns The created Entity with all given parameters.
 */
newton::Entity::Entity(glm::vec2 pos, float maxVel, float mass, float w, float h,float restitution, float friction, bool isStatic, bool gravityAffected, 
  int collPriority, int displayPriority, std::vector<std::string> labels, std::vector<std::string> noColl) : m_pos(pos), m_maxVel(maxVel), m_mass(mass), m_w(w), m_h(h),
  m_restitution(restitution), m_friction(friction), m_isStatic(isStatic), m_gravityAffected(gravityAffected), m_collPriority(collPriority), m_displayPriority(displayPriority),
  m_labels(labels), m_noColl(noColl)
{
  // manual constructor
}

/**
 * @brief Constructs an Entity from an already existing Entity. (Essentually a copy constructor).
 * 
 * @param entity the Entity to be copied.
 * 
 * @return A deep copy of the inputted Entity. (Identical, but different objects with no references to one another).
 */
newton::Entity::Entity(const newton::Entity& entity) : m_pos(entity.m_pos), m_maxVel(entity.m_maxVel), m_mass(entity.m_mass), m_w(entity.m_w), m_h(entity.m_h),
  m_restitution(entity.m_restitution), m_friction(entity.m_friction), m_isStatic(entity.m_isStatic), m_gravityAffected(entity.m_gravityAffected),
  m_collPriority(entity.m_collPriority), m_displayPriority(entity.m_displayPriority), m_labels(entity.m_labels), m_noColl(entity.m_noColl)
{
  // copy constructor
}

/**
 * @brief Applies a force on this.
 * 
 * @param f the force to be applied.
 */
void newton::Entity::Entity::applyForce(glm::vec2 f)
{
  this->m_acc += f;
}

/**
 * @brief Checks if two Entities are colliding
 * 
 * @param a the first Entity.
 * @param b the second Entity.
 * 
 * @returns If the Entities are colliding.
 */
bool newton::Entity::checkCollide(newton::Entity& a, newton::Entity& b)
{
  // steals collsion code from prototype
}

/**
 * @brief Adjusts the positions and velocities of two Entities if they collide.
 * 
 * @param a the first Entity.
 * @param b the second Entity.
 */
void newton::Entity::entityCollide(newton::Entity& a, newton::Entity& b)
{
  // most likely steals collision code from prototype
}