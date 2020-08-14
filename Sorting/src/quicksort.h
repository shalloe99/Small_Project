/*
 * quicksort.h
 *
 *  Created on: Nov 4, 2019
 *      Author: zshaw
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */


template <class Type>
void SwapQuick( Type &v1, Type &v2 )
{
	Type v3 = v1;
	v1 = v2;
	v2 = v3;
}

template <class Type>
int partition(Type* data, int start, int end){
	Type pivot = data[end];
	int pivot_spot = start;
	for (int j = start; j <= end -1;j++)
	{
		if(data[j] < pivot)
		{
			SwapQuick(data[j],data[pivot_spot]);
			pivot_spot ++;
		}
	}
	SwapQuick(data[pivot_spot],data[end]);
	return pivot_spot;

}

template <class Type>
void quicksort(Type* data, int start, int end){

	if (start < end){

		int pivot_spot = partition(data,start,end);
		quicksort(data,start,pivot_spot-1);
		quicksort(data,pivot_spot+1,end);
	}
}


#endif /* QUICKSORT_H_ */
