
// Gibbs.h
#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "mathfunctions.h"
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;
using Eigen::Vector3d;

#ifndef Gibbs 
#define Gibbs
extern double mu;


Vector3d GibbsV2( Vector3d& r1v, Vector3d& r2v, Vector3d& r3v) {

	Vector3d n = r1v.norm() * r2v.cross(r3v) + r2v.norm() * r3v.cross(r1v) + r3v.norm() * r1v.cross(r2v);
	Vector3d d = r1v.cross(r2v) + r2v.cross(r3v) + r3v.cross(r1v);
	Vector3d s = (r2v.norm() - r3v.norm()) * r1v + (r3v.norm() - r1v.norm()) * r2v + (r1v.norm() - r2v.norm()) * r3v;
	Vector3d VelocityVec2 = sqrt(mu / (n.norm() * d.norm())) * ((d.cross(r2v) / r2v.norm()) + s);

	Vector3d test = r1v.norm() * r2v.cross(r3v) + r2v.norm() * r3v.cross(r1v); //* r2v.cross(r3v);

	cout << "test " << test << endl;

	return VelocityVec2;
}
void test() {
	MatrixXd m(2, 2);
	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	cout << m << endl;
}
//vector<double> cross23 = cross(r2v,r3v);


#endif
