#include <string.h>
#include <stdbool.h>

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
