// mathfunctions.h

#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<double> scalarxvector(double& s, vector<double>& v) {
	vector<double> result = { 0,0,0 };
	for (size_t i = 0; i < 3; i++) {
		result[i] = v[i] * s;
	}

	return result;
}

vector<double> addvectors(vector<double>& v1, vector<double>& v2) {
	vector<double> v1plusv2 = { 0,0,0 };
	for (size_t i = 0; i < 3; i++) {
		v1plusv2[i] = v1[i] + v2[i];
	}
	return v1plusv2;
}

double dot(vector<double>& a, vector<double>& b) {
	double c = 0.0;
	for (size_t i = 0; i < 3; i++) {
		c += a[i] * b[i];
	}
	return c;
}


double norm(const vector<double>& a) {
	double normA = 0.0;
	for (size_t i = 0; i < 3; i++) {
		normA += a[i] * a[i];
	};
	normA = sqrt(normA);
	return normA;
}

 vector<double> cross(vector<double>& v1, vector<double>& v2) {
	vector<double> crossproduct(3);

	crossproduct[0] = v1[1] * v2[2] - v1[2] * v2[1];
	crossproduct[1] = v1[2] * v2[0] - v1[0] * v2[2];
	crossproduct[2] = v1[0] * v2[1] - v1[1] * v2[0];

	return crossproduct;
}
