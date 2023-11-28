// OrbitalElementsFromr2vr2.h
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "mathfunctions.h"
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;
using Eigen::Vector3d;

#ifndef OrbitFromAE
#define OrbitFromAE
extern double mu;
MatrixXd orbitTrajectoryPoints1(double& a, double& e) {
	MatrixXd rvectors2(360, 2);
	MatrixXd rMagnitudes2(360, 2);
	double SemiLatusRectum = a * (pow(e, 2) - 1);
	for (int i = 0; i < 360; ++i) {
		double trueAnomaly = i * 3.14159 / 180;
		double rMag = SemiLatusRectum / (1.0 + e * cos(trueAnomaly));

		rMagnitudes2(i, 0) = trueAnomaly;  // Example, replace with actual values
		rMagnitudes2(i, 1) = rMag;


		rvectors2(i, 0) = rMag * cos(trueAnomaly);
		rvectors2(i, 1) = rMag * sin(trueAnomaly);

		
	}
	//cout << "help " << rMagnitudes2 << endl;
	return rvectors2;
}
#endif