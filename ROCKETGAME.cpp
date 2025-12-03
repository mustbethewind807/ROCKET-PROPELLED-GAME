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

// error callback function
void error_callback(int error, const char* description) {
    std::cerr << "GLFW Error " << error << ": " << description << "\n";
}

// other functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height); // window resize callback

int main()
{
  // Example usage of std::vector to ensure C++23 features are supported
  std::vector<float> a {5, 5};

  // example output to verify program runs
  std::cout << "Hello, Rocket Game!\n";

  // make window wow
  glfwSetErrorCallback(error_callback);

  // make window
  if(!glfwInit())
  {
    std::cout << "GLFW failed to initialize";
    return 1;
  }

  // setup
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  GLFWwindow* window = glfwCreateWindow(800, 600, "ROCKET PROPELLED GAME", NULL, NULL);

  // does exactly what you think
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window\n";
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  // does exactly what you think
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD\n";
    return 1;
  }

  // viewport and window stuff
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // main loop
  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // exit loop
  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}  
