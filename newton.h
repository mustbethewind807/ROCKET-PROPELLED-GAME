#ifndef NEWTON_H
#define NEWTON_H

typedef struct
{
  float pos[2];
  float dest[2];
  float lerpPower;
} Camera;

typedef struct
{
  float pos[2];
  float prevPos[2];
  float vel[2];
  float acc[2];
  float maxVel;
  float m;
  float w;
  float h;
  float friction;

  bool isStatic;
  bool gravityAffected;
  float restitution;
  int collPriority;
  int displayPriority;

  char labels[8][17];
  char noColl[][17];
} Entity;

typedef struct
{
  Entity entity;
  char type;
} Action;

typedef struct
{
  int maxEntities;
  Entity entities[64]; // temporary i'll try to find a better way
  Action actions[64]; // again temporary i'll find a better way
  float gravity[2];
} Engine;

// Vector functions
float* vectorCreate(float, float);
float* vectorAdd(float*, float*);
float* vectorSub(float*, float*);
float* vectorMult(float*, float);
float* vectorDiv(float*, float);
float vectorMagSq(float*);
float vectorMag(float*);
float* vectorNormalize(float*);
float vectorDot(float*, float*);
float vectorCross(float*, float*);
float* vectorLimit(float*, float);
float* vectorLerp(float*, float*, float);
float* vectorCopy(float*);
void vectorSet(float*, float, float);

// Camera functions
void cameraLink(Camera, Entity);
void cameraUnlink(Camera);
void cameraUpdate(Camera);
void cameraRender(Camera, Engine);

// Entity functions
void applyForce(Entity, float*);
void checkCollide(Entity, Entity);
void entityCollide(Entity, Entity);

// Engine functions
void updateEngine(Engine);
void addAction(Engine, Action);
void runActions(Engine);
void clearActions(Engine);
void addEntity(Engine, Entity);
void removeEntity(Engine, Entity);

#endif /*NEWTON_H*/
