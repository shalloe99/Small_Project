//============================================================================
// Name        : Recursive.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int recursive(int n){
	if(n==0){
		return 2;
	}else if(n == 1){
		return 1;
	}else{
		return recursive(n - 1) + recursive(n-2);
	}
}
int main() {
	int n;
	cin>>n;
	cout<<"n: "<<recursive(n)<<endl;
	return 0;
}
