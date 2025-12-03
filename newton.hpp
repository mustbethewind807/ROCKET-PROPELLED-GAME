#ifndef NEWTON_H
#define NEWTON_H

// c++ libraries
#include <vector>
#include <string>

// glm libraries
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec2.hpp>

using namespace glm;

/**
 * @brief An entity structure.
 * 
 * Is a physics body that can interact with other Entities through an Engine.
 */
typedef struct
{
  vec2 pos;                        // The current position of the Entity.
  vec2 prevPos;                    // The position of the Entity on the previous update cycle.
  vec2 vel;                        // The current velocity of the Entity.
  vec2 acc;                        // The force that will be applied on the next update cycle.

  float maxVel;                    // The maximum velocity of the Entity.
  float mass;                      // The mass of the Entity.
  float w;                         // The width of the Entity.
  float h;                         // The height of the Entity.

  float restitution;               // The "bounciness" of the Entity.
  float friction;                  // The friction of the Entity.

  bool isStatic;                   // Can the Entity be moved?
  bool gravityAffected;            // Is the Entity affected by gravity?
  int collPriority;                // The priority of the Entity during collision checks. Higher = greater priority.
  int displayPriority;             // The priority of the Entity during rendering. Higher = rendered first

  std::vector<std::string> labels; // The tags of the Entity.
  std::vector<std::string> noColl; // What tags to avoid while doing collsion checks.
} Entity;

/**
 * @brief A camera object.
 * 
 * Is an object that is able to render Entities onto the screen using some math.
 */
typedef struct
{
  vec2 pos;          // The current position of the Camera.
  bool linked;       // Is the Camera linked to an active Entity?
  Entity linkObject; // The Entity the Camera is linked to.
  float lerpPower;   // How fast should the Camera move? 0 means the Camera does not move, while 1 means the Camera always snaps to the position of the linked Entity.
} Camera;

/**
 * @brief An action for an Engine to perform.
 * 
 * Contains an Entity for the Engine to operate on, and a type for what the Engine should do.
 */
typedef struct
{
  Entity entity;    // The entity the Engine should operate on.
  std::string type; // What the Engine should do with the Entity.
} Action;

/**
 * @brief An engine object.
 * 
 * Is an Engine that operates on Entities to run a simulation of a world filled with physics bodies.
 */
typedef struct
{
  std::vector<Entity> Entities; // The Entities within the Engine's world
  std::vector<Action> Actions;  // Special actions the Engine performs at the end of the next update cycle.
  vec2 gravity;                 // A constant force applied onto all Entities inside the Engine each update cycle.
} Engine;

// Camera functions
void cameraLink(Camera, Entity);
void cameraUnlink(Camera);
void cameraUpdate(Camera);
void cameraRender(Camera, Engine);

// Entity functions
void applyForce(Entity, vec2);
bool checkCollide(Entity, Entity);
void entityCollide(Entity, Entity);

// Engine functions
void updateEngine(Engine);
void addAction(Engine, Action);
void runActions(Engine);
void clearActions(Engine);
void addEntity(Engine, Entity);
void removeEntity(Engine, Entity);

#endif /*NEWTON_H*/
