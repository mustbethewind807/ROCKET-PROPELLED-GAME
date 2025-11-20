#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Camera
{
  float pos[2];
  float dest[2];
  float lerpPower;
};

struct Entity
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

  bool gravityAffected;
  float restitution;
  int collPriority;
  bool isStatic;
  int displayPriority;

  char* label;
  char* noColl[];
};

struct Engine
{
  int maxEntities;
  struct Entity entities[64]; // temporary i'll try to find a better way
  float gravity[2];
};

float* vectorCreate(float x, float y)
{
  float* out = (float*)malloc(2 * sizeof(float));

  if (out == NULL)
  {
	printf("Memory allocation failed");
	exit(EXIT_FAILURE);
  }

  out[0] = x;
  out[1] = y;

  return out;
}

float* vectorAdd(float* a, float* b)
{
  float* out = (float*)malloc(2 * sizeof(float));

  if (out == NULL)
  {
	printf("Memory allocation failed");
	exit(EXIT_FAILURE);
  }

  out[0] = a[0] + b[0];
  out[1] = a[0] + b[1];

  return out;
}

float* vectorSub(float* a, float* b)
{
  float* out = (float*)malloc(2 * sizeof(float));

  if (out == NULL)
  {
	printf("Memory allocation failed");
	exit(EXIT_FAILURE);
  }

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];

  return out;
}

float* vectorMult(float* a, float n)
{
  float* out = (float*)malloc(2 * sizeof(float));

  if (out == NULL)
  {
	printf("Memory allocation failed");
	exit(EXIT_FAILURE);
  }

  out[0] = a[0] * n;
  out[1] = a[1] * n;

  return out;
}

float* vectorDiv(float* a, float n)
{
  float* out = (float*)malloc(2 * sizeof(float));

  if (out == NULL)
  {
	printf("Memory allocation failed");
	exit(EXIT_FAILURE);
  }

  out[0] = a[0] / n;
  out[1] = a[1] / n;

  return out;
}
