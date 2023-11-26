
// Gibbs.h
#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "mathfunctions.h"

using namespace std;

#ifndef Gibbs 
#define Gibbs


vector<double> GibbsV2( vector<double>& r1v, vector<double>& r2v, vector<double>& r3v) {
	
	double velocityMag2 = 0.0;
	//norms
	double norm1 = norm(r1v);
	double norm2 = norm(r2v);
	double norm3 = norm(r3v);
	//crosses
	vector<double> cross23= cross(r2v, r3v);
	vector<double> cross12 = cross(r1v, r2v);
	vector<double> cross31 = cross(r3v, r1v);
	//vectors and scalars for calc of v2
	vector<double> n1 = scalarxvector(norm1,cross23);
	vector<double> n2 = scalarxvector(norm2, cross31);
	vector<double> n3 = scalarxvector(norm3, cross12);
	vector<double> n12 = addvectors(n1, n2);
	//n
	vector<double> n = addvectors(n12, n3);


	cout << "help " << n[1] << endl;
	return n;
}
//vector<double> cross23 = cross(r2v,r3v);


#endif
