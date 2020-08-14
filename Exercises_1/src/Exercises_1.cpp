//============================================================================
// Name        : Exercises_1.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point // Question 1
{
public:
	float x;
	float y;

	Point(float x, float y):x(x),y(y){}
	Point operator+(const Point& point2){
		float point3_X= point2.x + x;
		float point3_Y= point2.y + y;
		Point point3(point3_X,point3_Y);
		return point3;
	}
};
class Shape // Question 2
{
protected:
	Point point;
public:
	Shape(Point point):point(point){}
	virtual void Print()=0;
};

class Circle : Shape // Question 3
{
private:
	float radius;
	Point point;
public:
	Circle(Point point, float r):radius(r),Shape(point),point(point){}
	virtual void Print(){
		cout<< "Circle at position "<< point.x<<","<<point.y<<" with radius "<<radius<<endl;
	}
};
class Square: Shape
{
private:
	float side;
	Point point;
public:
	Square(Point point, float r):side(r),Shape(point),point(point){}
	virtual void Print(){
		cout<< "Square at position "<< point.x<<","<<point.y<<" with side "<<side<<endl;
	}
};

int main() {
	// Question 4
	Point point(2,5);
	Circle circle(point,3);
	circle.Print();
	Square square(point,4);
	square.Print();
	return 0;
}


