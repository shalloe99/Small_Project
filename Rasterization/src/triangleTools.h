/*
 * triangleTools.h
 *
 *  Created on: Jan 29, 2020
 *      Author: zshaw
 */

#ifndef TRIANGLETOOLS_H_
#define TRIANGLETOOLS_H_

#include <string>
#include <vector>
#include <algorithm>
//#include "drawTools.h"
#include "component.h"

class TriangleTools
{
public:

	TriangleTools();
	virtual ~TriangleTools();
	BoundingBox findBoundingBox(triangle temp);
	BoundingBox findBigBoundingBox(vector<triangle> temp);
	//int getWidth() const { return width; }
	//int getHeight() const { return height; }

};





#endif /* TRIANGLETOOLS_H_ */
