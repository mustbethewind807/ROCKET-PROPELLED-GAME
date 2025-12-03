// ROCKETGAME.cpp: Contains the main function and most gameplay stuff

// newton.hpp is my crappy game engine
#include "newton.hpp"

// standard libraries (i use the old c libraries because i forget std:: ones exist)
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// glad and glfw for graphics
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
  // Example usage of std::vector to ensure C++23 features are supported
  std::vector<float> a {5, 5};

  // example output to verify program runs
  std::cout << "Hello, Rocket Game!\n";

  // make window
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  GLFWwindow* window = glfwCreateWindow(800, 600, "ROCKET PROPELLED GAME", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window\n";
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  return 0;
}
