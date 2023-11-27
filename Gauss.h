// Gauss.h
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <Eigen/Eigen>
//#include <EigenU>

using namespace std;
using Eigen::MatrixXd;
using Eigen::Vector3d;
using Eigen::VectorXd;

#ifndef Gauss
#define Gauss
extern double mu;

MatrixXd RvectorsGauss(MatrixXd& L, MatrixXd& R, Vector3d& times) {
	MatrixXd DistVecs(3, 3);
	//MatrixXd Dmat(3, 3);
	//extracting L and R
	Vector3d L1 = { L(0,0), L(0,1), L(0,2) };
	Vector3d L2 = { L(1,0), L(1,1), L(1,2) };
	Vector3d L3 = { L(2,0), L(2,1), L(2,2) };

	Vector3d R1 = { R(0,0), R(0,1), R(0,2) };
	Vector3d R2 = { R(1,0), R(1,1), R(1,2) };
	Vector3d R3 = { R(2,0), R(2,1), R(2,2) };
	// taus
	double tau1 = times(1) - times(2);
	double tau3 = times(3) - times(2);
	double tau13 = times(3) - times(1);
	// 10 triple products
	double D0 = L1.dot(L2.cross(L3));
	double D11 = R1.dot(L2.cross(L3));
	double D21 = R2.dot(L2.cross(L3));
	double D31 = R3.dot(L2.cross(L3));
	double D12 = R1.dot(L1.cross(L3));
	double D22 = R2.dot(L1.cross(L3));
	double D32 = R3.dot(L1.cross(L3));
	double D13 = R1.dot(L1.cross(L2));
	double D23 = R2.dot(L1.cross(L2));
	double D33 = R3.dot(L1.cross(L2));
	//Coeffs A and B, acoeff,bcoeff, and ccoeff
	double A= 1 / D0 * (-tau3 / tau13 * D12 + D22 + tau1 / tau13 * D32);
	double B = 1 / (6 * D0) * (-(pow(tau13,2) - pow(tau3,2)) * tau3 / tau13 * D12 + (pow(tau13, 2) - pow(tau1, 2)) * tau1 / tau13 * D32);
	double acoeff = -pow(A,2) - 2 * A * L2.dot(R2) - pow(R2.norm(),2);
	double bcoeff = (-2) * mu * B * (A + L2.dot(R2));
	double ccoeff = -pow(mu,2) * pow(B,2);

	VectorXd coefficients(4);
	coefficients << 1, -6, 11, -6;  // Example: x^3 - 6x^2 + 11x - 6
	Eigen::Vector3d coeff(-0.2151830138973625, -0.3111717537041549, 0.708563939215852);
	//PolynomialSolver<double, Eigen::Dynamic> solver;
	//solver.compute(coeff);
	//const Eigen::PolynomialSolver<double, Eigen::Dynamic>::RootsType& r = solver.roots();
	return DistVecs;

}


#endif
