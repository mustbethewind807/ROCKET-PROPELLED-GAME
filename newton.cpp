#include "newton.hpp"

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec2.hpp>

/**
 * @brief Links an entity to a Camera.
 * 
 * @param cam the Camera to link to
 * @param entity the Entity to link to the Camera
 */
void newton::cameraLink(Camera cam, Entity e)
{
  cam.linkObject = e;
}

/**
 * @brief Unlinks a Camera from active entities.
 * 
 * Will generate an inactive entity used to track the Camera's destination
 * 
 * @param cam the Camera to unlink
 */
void newton::cameraUnlink(Camera cam)
{
  // unlink function
}

/**
 * @brief Updates a Camera based on its linked Entity.
 * 
 * @param cam the Camera to update
 */
void newton::cameraUpdate(Camera cam)
{
  // lerping stuff idk
}

/**
 * @brief Renders entities inside an Engine using a Camera.
 * 
 * @param cam the Camera to use
 * @param engine the Engine whose entities will be used
 */
void newton::cameraRender(Camera cam, Engine engine)
{
  // oh god
}

/**
 * @brief Apply a force to an entity.
 * 
 * @param entity the Entity to apply a force to
 * @param f the force to apply
 */
void newton::applyForce(Entity entity, glm::vec2 f)
{
  glm::vec2 a = f * 0.5f;
  entity.acc += a;
}

/**
 * @brief Checks to see if 2 Entities are colliding.
 * 
 * @param a the first Entity
 * @param b the second Entity
 * 
 * @return bool Did `a` and `b` collide?
 */
bool newton::checkCollide(Entity a, Entity b)
{
  return (
    a.pos.x + a.w / 2 > b.pos.x - b.w / 2 &&
    a.pos.x - a.w / 2 < b.pos.x + b.w / 2 &&
    a.pos.y + a.h / 2 > b.pos.y - b.h / 2 &&
    a.pos.y - a.h / 2 < b.pos.y + b.h / 2
  );
}

/**
 * @brief Resolves collisions between 2 Entities.
 * 
 * @param a the first Entity
 * @param b the second Entity
 */
void newton::entityCollide(Entity a, Entity b)
{
  // collision
}

/**
 * @brief Updates all entities within an Engine.
 * 
 * @param engine the engine to update
 */
void newton::updateEngine(Engine engine)
{
  // update engine
}

/**
 * @brief Add an Action to an Engine's action stack.
 * 
 * @param engine the Engine to add an Action to
 * @param action the Action to add
 */
void newton::addAction(Engine engine, Action action)
{
  engine.Actions.push_back(action);
}

/**
 * @brief Resolves all actions in an Engine's action stack.
 * 
 * @param engine the Engine to update
 */
void newton::runActions(Engine engine)
{
  for (const Action& action : engine.Actions)
  {
    // run actions
  }
}

/**
 * @brief Removes all actions in an Engine's action stack.
 * 
 * @param engine the Engine to clear actions for
 */
void newton::clearActions(Engine engine)
{
  engine.Actions.clear();
  std::vector<Action>().swap(engine.Actions);
}

/**
 * @brief Adds an Entity to an Engine via Actions.
 * 
 * @param engine the Engine to add the Entity to
 * @param entity the Entity to add
 */
void newton::addEntity(Engine engine, Entity entity)
{
  engine.Entities.push_back(entity);
}

/**
 * @brief Removes an Entity from an Engine via Actions.
 * 
 * @param engine the Engine to use
 * @param entity the Entity to remove
 */
void newton::removeEntity(Engine engine, Entity entity)
{
  // remove entity
}

