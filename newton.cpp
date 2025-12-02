#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>


// Vector functions (my vectors are float arrays of size 2)

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

float* vectorCopy(float* a)
{
  float* out = (float*)malloc(2 * sizeof(float));
  out[0] = a[0];
  out[1] = a[1];
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

float vectorMagSq(float* a)
{
  float out = a[0] * a[0] + a[1] * a[1];

  return out;
}

float vectorMag(float* a)
{
  return sqrtf(vectorMagSq(a));
}

float* vectorNormalize(float* a)
{
  float* b = vectorCopy(a);
  float m = vectorMag(a);
  float* c = vectorDiv(b, m);
  free(b);
  b = NULL;
  return c;
}

float vectorDot(float* a, float* b)
{
  return a[0] * b[0] + a[1] * b[1];
}

float vectorCross(float* a, float* b)
{
  return a[0] * b[1] - a[1] * b[0];
}

float* vectorLimit(float* a, float n)
{
  if (vectorMagSq(a) < n * n) return vectorCopy(a);

  float* out = vectorCopy(a);
  out = vectorNormalize(out);
  out = vectorMult(out, n);
  return out;
}

float* vectorLerp(float* a, float* b, float t)
{
  float* c = vectorSub(b, a);
  c = vectorMult(c, t);
  return vectorAdd(c, a);
}

void vectorSet(float* a, float x, float y)
{
  a[0] = x;
  a[1] = y;
}
