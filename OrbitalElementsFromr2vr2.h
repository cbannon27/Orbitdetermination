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

#ifndef OrbitalElementsFromr2vr2
#define OrbitalElementsFromr2vr2
extern double muTest;
//extern float maxVal;
	MatrixXd orbitTrajectoryPoints(Vector3d& r2v, Vector3d& v2v) {
		MatrixXd rvectors(360, 2);
		MatrixXd rMagnitudes(360, 2);
		//basis vectors
		Vector3d I = { 1,0,0 };
		Vector3d J = { 0,1,0 };
		Vector3d K = { 0,0,1 };
		//getting elements
		Vector3d h = r2v.cross(v2v);
		double hmag = h.norm();
		Vector3d Kcrossh = K.cross(h);
		Vector3d evec = 1 / muTest * v2v.cross(h) - r2v / r2v.norm();
		double eccentricity = evec.norm();
		double SemiLatusRectum = pow(hmag,2) / 3.986e+05;
		double a = SemiLatusRectum / (1.0 - pow(eccentricity, 2));
		Vector3d n = Kcrossh / Kcrossh.norm();
		double Inclination = acos(h.dot(K) / h.norm());
		double RAAN = atan(n.dot(J) / n.dot(I));
		double ArgofPeri = -acos(evec.dot(n) / eccentricity);
		
		//double SemiLatusRectum = a * (pow(eccentricity, 2) - 1);
		for (int i = 0; i < 360; ++i) {
			double trueAnomaly = i * 3.14159 / 180;
			double rMag = SemiLatusRectum / (1.0 + eccentricity * cos(trueAnomaly));

			rMagnitudes(i, 0) = trueAnomaly;  // Example, replace with actual values
			rMagnitudes(i, 1) = rMag;


			rvectors(i, 0) = rMag * cos(trueAnomaly);//* cos(trueAnomaly);
			rvectors(i, 1) = rMag * sin(trueAnomaly);


		}

	
		
		return rvectors;
	}

	


#endif
