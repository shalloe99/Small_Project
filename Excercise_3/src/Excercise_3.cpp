//============================================================================
// Name        : Excercise_3.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Excercise_3.h"
#include <math.h>
using namespace std;

template<class T,int dimension>
float Euclidean(Point<T,dimension> p1, Point<T,dimension> p2){
	float rval = 0;
	for ( int i = 0; i < dimension; i++ ) {
	      rval = rval + pow(p1.getPoint(i) - p2.getPoint(i),2);
	   }
	return sqrt(rval);
}
int main() {
	int array_int1[] = {12,32};
	int array_int2[] = {23,43};
	Point<int,2> point1(array_int1);
	Point<int,2> point2(array_int2);
	cout<< Euclidean<int,2>(point1,point2)<<endl;
	float array_float1[] = {2.3,2.4,3.2};
	float array_float2[] = {5.7,3.4,-1.2};
	Point<float,3> point3(array_float1);
	Point<float,3> point4(array_float2);
	cout<< Euclidean<float,3>(point3,point4)<<endl;
	return 0;
}


