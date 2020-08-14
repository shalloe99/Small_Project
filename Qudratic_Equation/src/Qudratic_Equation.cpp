//============================================================================
// Name        : Qudratic_Equation.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float A,B,C;
	float root1 = 0;
	float root2 = 0;
	string condition = "";
	cin >> A;
	cin >> B;
	cin >> C;
	cout<<A<<"x^2 ";
	//Output equation B-case
	if(B<0){
		cout<<"- "<<abs(B)<<"x ";
	}else{
		cout<<"+ "<<B<<"x ";
	}
	//Output equation C-case
	if(C<0){
			cout<<"- "<<abs(C)<<" = 0"<<endl;
		}else{
			cout<<"+ "<<C<<" = 0"<<endl;
		}
	if((A==0)and(B==0)){
	cout<<"Unable to determine root(s)."<<endl;
	}else{
		if(A==0){
			root1 = -C/B;
			condition = "one root";
			cout << "x = "<<root1<<endl;
		}else{
			float determinator = B*B - 4*A*C;
			if(determinator > 0){
				root1 = (-B +sqrt(determinator))/(2*A);
				root2 = (-B -sqrt(determinator))/(2*A);
				if(A>0){
					if(root1<root2)
				{cout << "x = "<<root1<<endl;
				cout << "x = "<<root2<<endl;}
				else{
					cout << "x = "<<root2<<endl;
					cout << "x = "<<root1<<endl;}
				}else{
					if(root1<root2)
				{cout << "x = "<<root2<<endl;
				cout << "x = "<<root1<<endl;}
				else{
					cout << "x = "<<root1<<endl;
					cout << "x = "<<root2<<endl;}
					}
				condition = "two root";
			}else if(determinator < 0){
				float real = -B/float(2*A);
				root1 = sqrt(fabs(determinator))/(2*A);
				if(real > 0){
					if(fabs(root1) > real){
					cout << "x = "<<real<<" + "<<fabs(root1)<<"i"<<endl;
					cout << "x = "<<real<<" - "<<fabs(root1)<<"i"<<endl;
				}else{
					cout << "x = "<<real<<" - "<<fabs(root1)<<"i"<<endl;
					cout << "x = "<<real<<" + "<<fabs(root1)<<"i"<<endl;
				}
			}else{
				if(root1>real){
				cout << "x = "<<real<<" - "<<fabs(root1)<<"i"<<endl;
				cout << "x = "<<real<<" + "<<fabs(root1)<<"i"<<endl;
			}else{
				cout << "x = "<<real<<" + "<<fabs(root1)<<"i"<<endl;
				cout << "x = "<<real<<" - "<<fabs(root1)<<"i"<<endl;
			}

			}


			}else{
				root1 = -B/(2*A);
				condition = "one root";
				cout << "x = "<<root1<<endl;
			}
		}
	}
	return 0;
}
