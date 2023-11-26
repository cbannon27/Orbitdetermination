
// Gibbs.h
#pragma once
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

#ifndef Gibbs 
#define Gibbs

double dot(vector<double>& a, vector<double>& b) {
	double c = 0.0;
	for (size_t i = 0; i < 3; i++) {
		c += a[i] * b[i];
	}
		return c;
}


double velocityMag2(vector<double>& Dist1vec, vector<double>& Dist2vec, vector<double>& Dist3vec) {

	double velocityMag2 = 0.0;
	
	return velocityMag2;
}



#endif
