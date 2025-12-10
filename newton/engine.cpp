#include "engine.hpp"

/**
 * @brief Creates an Engine with the default gravity.
 * 
 * @returns An Engine with default gravity.
 */
newton::Engine::Engine()
{
  this->m_gravity = glm::vec2(0.0f, 1.0f);
}

/**
 * @brief Creates an Engine with a parameter for gravity.
 * 
 * @param gravity the gravity for the engine.
 * 
 * @returns An Engine with the specified gravity.
 */
newton::Engine::Engine(glm::vec2 gravity) : m_gravity(gravity) {}

/**
 * @brief Outputs a list of all the Entities inside of an Engine.
 * 
 * @returns A std::vector of Entities.
 */
std::vector<newton::Entity*> newton::Engine::getEntities()
{
  return this->m_entities;
}