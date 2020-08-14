/*
 * triangleTools.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: zshaw
 */

#include <iostream>
#include "triangleTools.h"

using namespace std;

TriangleTools::TriangleTools()
{
}

TriangleTools::~TriangleTools()
{
}
BoundingBox TriangleTools::findBoundingBox(triangle temp) {
	double xmin = temp.points[0].x;
	double xmax = temp.points[0].x;
	double ymin = temp.points[0].y;
	double ymax = temp.points[0].y;
	for (int i = 0; i < 3; i++) {
		xmin = min(xmin, temp.points[i].x);
		ymin = min(ymin, temp.points[i].y);
		xmax = max(xmax, temp.points[i].x);
		ymax = max(ymax, temp.points[i].y);
	}
	BoundingBox result = { xmin, xmax, ymin, ymax };
	return result;
}
BoundingBox TriangleTools::findBigBoundingBox(vector<triangle> temp) {
	double xmin = temp[0].points[0].x;
	double xmax = temp[0].points[0].x;
	double ymin = temp[0].points[0].y;
	double ymax = temp[0].points[0].y;
	for (triangle s : temp) {
		BoundingBox tempBox = findBoundingBox(s);
		//	cout << "Now - xmin: " << xmin << " xmax: " << xmax << " ymin: " << ymin << " ymax: " << ymax << endl;
		//	cout << "next - xmin: " << tempBox.xmin << " xmax: " << tempBox.xmax << " ymin: " << tempBox.ymin << " ymax: " << tempBox.ymax << endl;
		xmin = min(xmin, tempBox.xmin);
		ymin = min(ymin, tempBox.ymin);
		xmax = max(xmax, tempBox.xmax);
		ymax = max(ymax, tempBox.ymax);
	}
	BoundingBox result = { xmin, xmax, ymin, ymax };
	return result;
}

