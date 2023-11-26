#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Gibbs.h"
#include "mathfunctions.h"
#include <Eigen/Dense>

using Eigen::Vector3d;

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
  Vector3d r1(3457.9, 456.5, -6006.4);
  Vector3d r2(3482.6, 479.0, -5990.6);
  Vector3d r3(3507.3, 501.5, -5974.6);
  //double normr1 = *norm(r1);

  double mu = 3.986E5;
  Vector3d n = GibbsV2(mu, r1, r2, r3);
  
  //vector<double> r1r2 = *addvectors(r1, r2);

  //cout << "vector test:" << r1[0] << r1r2[1] << r1r2[2] << endl;
  cout << "help " << n << endl;
  //end testing
  return 0;
}