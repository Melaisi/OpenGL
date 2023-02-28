#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Classes to draw different things.
#include "SierpinskiGasket.h"

#include "Drawable.h"
#include "Sphere.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Chapter2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error! Need to be initialize after an openGL context\n";
    }

    // print out gl version
    std::cout << glGetString(GL_VERSION) <<std::endl;

    // Test SierpinskiGasket
    //SierpinskiGasket sg;

    // Test a sphere class
    Drawable* model = new Sphere();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Get inital time
        double initial_time_s = glfwGetTime();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        model->draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        // Wait one second
        // while ((glfwGetTime() - initial_time_s) <= 1/25) {}
    }

    glfwTerminate();
    return 0;
}