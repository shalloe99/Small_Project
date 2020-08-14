#include <iostream>
#include <cstring>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int Customer::counter = 0; // defines and initializes

Customer::Customer(int customerID, const char name[], bool credit)
:id(customerID),credit(credit),balance(0){
	setName(name);
	for(int i = 0;i < 5;i++)
		strcpy(productsPurchased[i],"");
}
int Customer::getID() const{
	return id;
}
const char* Customer::getName() const{
	return name;
}
void Customer::setName(char const customerName[]){
	if (strlen(customerName) > 0) {
	        strcpy(this->name, customerName);
	    }
	    else {
	        counter++;
	        ostringstream oss;
	        oss << "Customer " << counter;
	        strcpy(this->name, oss.str().c_str());
	    }
}
bool Customer::getCredit() const{
	return credit;
}
void Customer::setCredit(bool hasCredit){
	credit = hasCredit;
}
double Customer::getBalance() const{
	return balance;
}
bool Customer::processPayment(double amount){
	if(amount < 0)
		return false;
	else{
		balance = balance + amount;
	}
	return true;
}
bool Customer::processPurchase(double amount, Product product){
	if (amount < 0)
		return false;
	else{
		if(credit==true){
			balance -= amount; // PurchaseProcess
			bool check = true;
			for(int i = 0;i < 5;i++)
				if(strcmp(productsPurchased[counter],product.getName())==0)
					check = false;
			if(check){
				if(counter >= 5)
					counter = 4;
				for(int i = 1;i < 5;i++)
					strcpy(productsPurchased[i-1],productsPurchased[i]);
				strcpy(productsPurchased[counter],product.getName());
				counter++;
			}
			return true;
		}else{
			if(balance >= amount){// PurchaseProcess
				balance -= amount;
				bool check = true;
				for(int i = 0;i < 5;i++)
					if(strcmp(productsPurchased[counter],product.getName())==0)
						check = false;
				if(check){
					strcpy(productsPurchased[counter],product.getName());
					counter++;
				}
				return true;
			}else{
				return false;
			}
		}
	}
}
void Customer::outputRecentPurchases(std::ostream& os) const{
	os << "Products Purchased --"<< endl;
	for(int i = counter-1; i >=0;i--){
		if(strlen(productsPurchased[i])>0)
			os<< this->productsPurchased[i]<<endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Customer& customer){
	os << "Customer Name: " << customer.getName() << endl;
	os << "Customer ID: " << customer.getID() << endl;
	os << "Has Credit: ";
	if (customer.getCredit())
		os << "true" << endl;
	else
		os << "false" << endl;
	os << "Balance: " << customer.getBalance() << endl;
	customer.outputRecentPurchases(os);
	return os;
}
// Widget Gidget
// Something nice
// Something old
// Something new
// Something borrowed
// Something blue
