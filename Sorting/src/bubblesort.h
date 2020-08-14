/*
 * bubblesort.h
 *
 *  Created on: Nov 4, 2019
 *      Author: zshaw
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

template <class Type>
void SwapBubble( Type &v1, Type &v2 )
{
	Type v3 = v1;
	v1 = v2;
	v2 = v3;
}

template <class Type>
void bubblesort(Type* data,int size){
	int i, j;
	for (i = 0; i < size-1; i++){
		for (j =0; j < size-i-1;j++){
			if(data[j]>data[j+1])
				SwapBubble(data[j], data[j+1]);
		}
	}
}

#endif /* BUBBLESORT_H_ */
