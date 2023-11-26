#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Gibbs.h"
#include "mathfunctions.h"

int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow( 500, 500, "Sine Curve using OpenGL with GLEW and GLFW", NULL, NULL );
  if ( !window ) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent( window );

  if ( glewInit() != GLEW_OK ) {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

  while ( !glfwWindowShouldClose( window ) ) {
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_LINES );
    // Draw X and Y axis
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex2f( -1.0, 0.0 );
    glVertex2f( 1.0, 0.0 );
    glVertex2f( 0.0, 1.0 );
    glVertex2f( 0.0, -1.0 );

    // Plot sine curve
    glColor3f( 0.0, 1.0, 0.0 );
    for ( float i = 0; i < 2 * 3.14159; i += 0.001 ) {
      float x = ( 2 * i - 3.14159 ) / 3.14159;
      float y = sin( i );
      glVertex2f( x, y - 0.001 );
      glVertex2f( x, y );
    }
    glEnd();

    glfwSwapBuffers( window );
    glfwPollEvents();
  }

  glfwTerminate();
  // testing
  vector<double> r1 = { 1,1,1 };
  vector<double> r2 = { 1,1,1 };
  vector<double> r3 = { 0,0,0 };
  //double normr1 = *norm(r1);
  vector<double> r1r2 = GibbsV2(r1, r2, r3);
  
  //vector<double> r1r2 = *addvectors(r1, r2);

  //cout << "vector test:" << r1[0] << r1r2[1] << r1r2[2] << endl;
  cout << "help " << r1r2[1] << endl;
  //end testing
  return 0;
}