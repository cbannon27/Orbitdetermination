#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Gibbs.h"
#include "OrbitalElementsFromr2vr2.h"
#include <Eigen/Dense>

using Eigen::Vector3d;


extern double mu = 3.986e+05;
int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow( 1500, 1500, "Orbit in Perifocal Frame", NULL, NULL );
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
  //trajectory points and inputs testing
  Vector3d r1(3457.9, 456.5, -6006.4);
  Vector3d r2(-9.169050298094448e+02, 4.050896256245320e+03, 1.434684965708947e+04);
  Vector3d r3(3507.3, 501.5, -5974.6);
  double mu = 3.986E5;
  Vector3d v2(-3.399213191633871, -2.334062343322431, 0.140908762431397);
  
  MatrixXd testt = orbitTrajectoryPoints(r2, v2);
  float maxVal = testt(180, 0) * 1.2;
 
  vector<GLfloat> points;
  for (int i = 0; i < testt.rows(); ++i) {
      for (int j = 0; j < testt.cols(); ++j) {
          GLfloat scaledVal = static_cast<GLfloat>(testt(i, j)) / maxVal;
          points.push_back(scaledVal);
      }
  }

  while ( !glfwWindowShouldClose( window ) ) {
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_LINES );
    // Draw X and Y axis
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex2f( -1.0, 0.0 );
    glVertex2f( 1.0, 0.0 );
    glVertex2f( 0.0, 1.0 );
    glVertex2f( 0.0, -1.0 );

    glEnd();
    glBegin(GL_LINE_STRIP);
    // Plot sine curve
    glColor3f( 0.0, 1.0, 0.0 );
    for ( float i = 0; i < points.size(); i += 2) {
      float x = points[i];
      float y = points[i+1];
      glVertex2f( x, y - 0.001 );
      glVertex2f( x, y );
    }

    glEnd();

    glfwSwapBuffers( window );
    glfwPollEvents();
    // Check for key presses
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

  }

  glfwTerminate();
  Vector3d ni = GibbsV2(r1, r2, r3);
  /*// testing
  Vector3d r1(3457.9, 456.5, -6006.4);
  Vector3d r2(3.482626561106062e+03, 4.789950633546905e+02, -5.990587686030816e+03);
  Vector3d r3(3507.3, 501.5, -5974.6);
  Vector3d v2(5.077842213569874, 4.623789027156017, 3.265755343622740);

  

  double mu = 3.986E5;
  Vector3d ni = GibbsV2(mu, r1, r2, r3);
  //MatrixXd testt = orbitTrajectoryPoints(r2, v2, mu);
  
  //vector<double> r1r2 = *addvectors(r1, r2);

  //cout << "vector test:" << r1[0] << r1r2[1] << r1r2[2] << endl;
  
  */
  cout << "help " << testt << endl;
  cout << "help " << ni << endl;
  //end testing
  return 0; 
}