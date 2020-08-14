//============================================================================
// Name        : Excercises_2.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point
{
private:
	float x;
	float y;
public:
	Point(){}
	Point(float x, float y):x(x),y(y){}
	~Point(){
		cout<<"Point (" <<x<<","<<y<<") Destructor is called."<<endl;
	}
	void print(){
		cout<<"Point (" <<x<<","<<y<<")" <<endl;
	}
};

int main() {
	Point* point1 = new Point(1,1);// Question 1
	point1->print();
	delete point1;
	cout<< endl;

	Point stack[5]; // Question 2
	for(int i = 0; i <5;i++){
		stack[i] = Point(i,i);
	}
	for(int i = 0; i <5;i++){
		stack[i].print();
	}
	cout<<endl;

	Point *heap = new Point[10]; // Question 3
	for(int i = 0; i <10;i++){
		heap[i] = Point(i,i);
	}
	for(int i = 0; i <10;i++){
		heap[i].print();
	}
	delete[] heap;
	return 0;
}

