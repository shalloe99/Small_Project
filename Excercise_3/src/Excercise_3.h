/*
 * Excercise_3.h
 *
 *  Created on: Sep 11, 2019
 *      Author: zshaw
 */

#ifndef EXCERCISE_3_H_
#define EXCERCISE_3_H_

template <class T, int dimension>
class Point{
private:
	T t[dimension];
public:
	Point(T arr[]){
		for (int i = 0;i < dimension;i++)
			t[i] = arr[i];
	}
	~Point(){}
	T getPoint(int n){return t[n];}
};

#endif /* EXCERCISE_3_H_ */
