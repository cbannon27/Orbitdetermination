#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Gibbs.h"

#include "OrbitalElementsFromr2vr2.h"
#include "OrbitFromAE.h"
#include "PlanetPoints.h"
#include <Eigen/Dense>
//#include <Eigen/src/Polynomials/PolynomialSolver.h>


using Eigen::Vector3d;


extern double muTest = 3.986e+05;
//extern double radius;
using namespace std;
//MatrixXd orbitTrajectoryPoints1(double SemiMajor, double ecc);
int main() {
  if ( !glfwInit() ) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }
  
  cout << "Choose a Mode:\n";
  cout << "1. Orbit Visualizer\n";
  cout << "2. Orbit Determination\n";
  

  // Get user input
  int choice1;
  std::cout << "Enter your choice: ";
  std::cin >> choice1;

  vector<GLfloat> points;
  vector<GLfloat> pointsP;
  MatrixXd test1(360,2);
  MatrixXd test2(360, 2);
  MatrixXd test3(360, 2);
  float maxVal;
  // Vector3d r1;
  // Vector3d r2;
  // Vector3d r3;
  // Vector3d v2;
  // Perform actions based on user input
  switch (choice1) {
  case 1:
      double SemiMajor, ecc;
      double radius;
      std::cout << "You chose Orbit Visualizer\n";
      // Perform actions for Option 1
      cout << "Choose a Planet:\n";
      cout << "1. Mercury\n";
      cout << "2. Venus\n";
      cout << "3. Earth\n";
      cout << "4. Mars\n";
      cout << "5. Jupiter\n";
      cout << "6. Saturn\n";
      cout << "7. Uranus\n";
      cout << "8. Neptune\n";
      // Get user input
      int choice2;
      std::cout << "Enter your choice: ";
      std::cin >> choice2;
      switch (choice2) {
      case 1:
          cout << "You chose Mercury\n";

          radius = 2440;
         
   
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

           points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 2:
          cout << "You chose Venus\n";
        //  double radius;
          radius = 6051.8;

          //double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 3:
          cout << "You chose Earth\n";
       //   double radius;
          radius = 6378.1;

       //   double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 4:
          cout << "You chose Mars\n";
      //    double radius;
          radius = 3389.5;

      //    double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }
          break;
      case 5:
          cout << "You chose Jupiter\n";
        //  double radius;
          radius = 69911.0;

        //  double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 6:
          cout << "You chose Saturn\n";
         // double radius;
          radius = 58232;

        //  double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 7:
          cout << "You chose Uranus\n";
        //  double radius;
          radius = 25362;

        //  double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity (e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      case 8:
          cout << "You chose Neptune\n";
        //  double 24622;
          radius = 24622;

       //   double SemiMajor, ecc;
          glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
          cout << "Enter the Semi Major Axis (> 0) and the Eccentricity ( e > 0). [separated by spaces]: ";
          cin >> SemiMajor >> ecc;
          orbitTrajectoryPoints1(SemiMajor, ecc);
          test1 = orbitTrajectoryPoints1(SemiMajor, ecc);
          PlanetPoints1(radius);
          test3 = PlanetPoints1(radius);
          maxVal = test1(180, 0) * 1.2;

          points;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
                  points.push_back(scaledVal);
              }
          }
          pointsP;
          for (int i = 0; i < test1.rows(); ++i) {
              for (int j = 0; j < test1.cols(); ++j) {
                  GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
                  pointsP.push_back(scaledVal);
              }
          }

          break;
      }
      break;
  case 2:
      radius = 6378.1;
     cout << "You chose Orbit Determination (Earth only).\n";
     // Prompt the user for input
     double r1x, r1y, r1z, r2x, r2y, r2z, r3x, r3y, r3z;
   /*  r1x = 3457.9;
     r1y = 456.51;
     r1z = -6006.4;
     r2x = 3482.6;
     r2y = 479;
     r2z = -5990.6;
     r3x = 3507.3;
     r3y = 501.47;
     r3z = -5974.6;
    */ 
     // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     cout << "Enter the x, y, z components of r1 (separated by spaces): ";
     cin >> r1x >> r1y >> r1z;
     cout << "Enter the x, y, z components of r2 (separated by spaces): ";
     cin >> r2x >> r2y >> r2z;
     cout << "Enter the x, y, z components of r3 (separated by spaces): ";
     cin >> r3x >> r3y >> r3z;
     
     //gibbs!
     Vector3d r1 = { r1x, r1y, r1z };
     Vector3d r2 = { r2x, r2y, r2z };
     Vector3d r3 = { r3x, r3z, r3z };
     Vector3d v2 = { 5.07784221356987, 4.62378902715602, 3.26575534362274 };
     Gibbs(r1, r2, r3);
    Vector3d v22 = Gibbs(r1, r2, r3);
     orbitTrajectoryPoints(r2, v22);
     test2 = orbitTrajectoryPoints(r2,v2);
     PlanetPoints1(radius);
     test3 = PlanetPoints1(radius);
     maxVal = test2(180,0)*1.1;

     points;
     for (int i = 0; i < test2.rows(); ++i) {
         for (int j = 0; j < test2.cols(); ++j) {
             GLfloat scaledVal = static_cast<GLfloat>(test2(i, j)) / maxVal;
             points.push_back(scaledVal);
         }
     }
     pointsP;
     for (int i = 0; i < test1.rows(); ++i) {
         for (int j = 0; j < test1.cols(); ++j) {
             GLfloat scaledVal = static_cast<GLfloat>(test3(i, j)) / maxVal;
             pointsP.push_back(scaledVal);
         }
     }
      // Perform actions for Option 1
      // Perform actions for Option 2
      break;
  
  }

  
  
  /*// Prompt the user for input
  double r2x, r2y, r2z, v2x, v2y, v2z;
  std::cout << "Enter the x, y, z components of r2 (separated by spaces): ";
  std::cin >> r2x >> r2y >> r2z;
  std::cout << "Enter the x, y, z components of v2 (separated by spaces): ";
  std::cin >> v2x >> v2y >> v2z;
  */
  GLFWwindow* window = glfwCreateWindow( 1500, 1500, "(Green) Orbit in Perifocal Frame, (Blue) Planet at center", NULL, NULL );
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

 // glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
  //trajectory points and inputs testing
  //Vector3d r1(3457.9, 456.5, -6006.4);
  //Vector3d r2(r2x, r2y, r2z);
  //Vector3d r3(3507.3, 501.5, -5974.6);
  //Vector3d v2(v2x, v2y, v2z);
  
  
 // MatrixXd test2 = orbitTrajectoryPoints2(r2, v2);

 /* float maxVal = test1(180, 0) * 1.2;
 
  vector<GLfloat> points;
  for (int i = 0; i < test1.rows(); ++i) {
      for (int j = 0; j < test1.cols(); ++j) {
          GLfloat scaledVal = static_cast<GLfloat>(test1(i, j)) / maxVal;
          points.push_back(scaledVal);
      }
  }
  */
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
    // Plot Orbit Points
    glColor3f( 0.0, 1.0, 0.0 );
    for ( float i = 0; i < points.size(); i += 2) {
      float x = points[i];
      float y = points[i+1];
      glVertex2f( x, y - 0.001 );
      glVertex2f( x, y );
    }

    glEnd();

    glBegin(GL_LINE_STRIP);
    // Plot Orbit planet
    glColor3f(0.0, 0.0, 1.0f);
    for (float i = 0; i < pointsP.size(); i += 2) {
        float x = pointsP[i];
        float y = pointsP[i + 1];
        glVertex2f(x, y - 0.001);
        glVertex2f(x, y);
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
  //Vector3d ni = GibbsV2(r1, r2, r3);
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
  //cout << "help " << test2 << endl;
  //cout << "help " << ni << endl;
  //end testing
  return 0; 
}