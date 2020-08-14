/*
 * heapsort.h
 *
 *  Created on: Nov 4, 2019
 *      Author: zshaw
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_
#include "Heap.h"
template <class Type>
void heapsort(Type* data, int size){
	Heap<Type> heap(data,size);
	int i;
	for (i = 0; i < size; i++){
		data[i] = heap.removeMin();
	}
}




#endif /* HEAPSORT_H_ */
