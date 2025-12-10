#include "camera.hpp"

/**
 * @brief Creates a Camera with default values.
 * 
 * @returns A "default" Camera.
 */
newton::Camera::Camera() : m_pos(glm::vec2(0.0f, 0.0f)), m_linked(false), m_linkedObject(nullptr), m_lerpSpeed(1)
{
  // most likely steals line 13 of ROCKETGAME.js
}

/**
 * @brief Links a Camera to an entity.
 * 
 * @param ref the Entity to link to.
 */
void newton::Camera::link(Entity& ref)
{
  this->m_linked = true;
  if (this->m_linkedObject != nullptr)
  {
    // dereference old object
    // remove if no longer reference anywhere else
  }

  // set pointer m_linkedObject to pointer of ref
}

/**
 * @brief Unlinks a Camera from any Entities.
 * 
 * Sets m_linked to false, and removes any references or pointers to objects.
 */
void newton::Camera::unlink()
{
  this->m_linked = false;
  this->m_linkedObject = nullptr;
}

/**
 * @brief Updates a Camera by one update cycle.
 */
void newton::Camera::update()
{
  // Move Camera based on linkedObject's position and this->m_pos
  // Maybe do some special stuff
}

/**
 * @brief Draws all simulated Entities in an Engine to a GLFWwindow.
 * 
 * @param engine the Engine whose Entities will be used.
 * @param window the window to draw to.
 */
void newton::Camera::render(newton::Engine& engine, GLFWwindow* window)
{
  // oh god
}