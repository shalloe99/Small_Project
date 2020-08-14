/*
 * mergesort.h
 *
 *  Created on: Nov 4, 2019
 *      Author: zshaw
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_


template<class Type>
void merge(Type data[],int start, int break_point, int end){
	// copy and create temp array
	int n1 = break_point-start+1;
	int n2 = end-break_point;
	int temp1[n1];
	int temp2[n2];
	for (int p = 0;p<n1; p++)
		temp1[p] = data[start+p];
	for (int h = 0; h<n2; h++)
		temp2[h] = data[break_point+1+h];
	int i = 0, j = 0, k=start;
	while (i<n1 and j<n2){
		if(temp1[i] <= temp2[j]){ //temp1 value is small
			data[k] = temp1[i];
			i++;
		}else{// temp2 value is small
			data[k] = temp2[j];
			j++;
		}
		k++;
	}

	// make sure all elements are empty
	while(i < n1){
		data[k] = temp1[i];
		k++;
		i++;
	}
	while(j < n2){
		data[k] = temp2[j];
		k++;
		j++;
	}

}

template<class Type>
void mergesort(Type* data, int start,int end){
	if (start < end){
		int break_point = start+(end-start)/2;
		mergesort(data,start,break_point);
		mergesort(data,break_point+1,end);
		merge(data,start,break_point,end);
	}
}

#endif /* MERGESORT_H_ */
