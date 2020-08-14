/*
 * component.h
 *
 *  Created on: Jan 29, 2020
 *      Author: zshaw
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

struct point { double x; double y; double z; };
struct triangle {
	point points[3];
	int R, G, B;
};
struct BoundingBox {
	double xmin, xmax, ymin, ymax;
};



#endif /* COMPONENT_H_ */
