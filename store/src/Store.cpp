#include <iostream>
#include <cstring>
#include <sstream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

int Store::counter = 0; // defines and initializes Store();
Store::Store(){
	setName("");
}
Store::Store(const char name[]):numProducts(0),numCustomers(0){
	setName(name);
}
const char* Store::getName(){
	return name;
}
void Store::setName(const char storeName[]){
	if (strlen(storeName) > 0) {
		strcpy(this->name, storeName);
	}else {
		counter++;
		ostringstream oss;
		oss << "Store " << counter;
		strcpy(this->name, oss.str().c_str());
	}
}
bool Store::addProduct(int productID, const char productName[]){
		if(numProducts>=100)
			return false;
		else{
			for(int i = 0; i < numProducts;i++){
				if(products[i]->getID() == productID)
						return false;
			}
				Product* product = new Product(productID,productName);
				products[numProducts] = product;
				numProducts ++;
				return true;
			//}
		}
}
Product* Store::getProduct(int productID){
	Product* product = nullptr;
	for(int i = 0; i < numProducts;i++){
		if(products[i]->getID() == productID){
			product = products[i];
			return product;}
	}
	return product;
//	throw runtime_error("Subject not found"+productID);
}
//// even though getProduct should be private, it helps autograding to make it public
bool Store::addCustomer(int customerID, const char customerName[], bool credit){
	if(numCustomers>=100)
				return false;
			else{
				for(int i = 0; i < numCustomers;i++){
					if(customers[i]->getID() == customerID)
							return false;
				}
					Customer* customer = new Customer(customerID,customerName,credit);
					customers[numCustomers] = customer;
					numCustomers ++;
					return true;
				//}
			}
}
Customer* Store::getCustomer(int productID){
	Customer* pointer = nullptr;
	for(int i = 0; i < numCustomers;i++){
		if(customers[i]->getID() == productID){
			pointer = customers[i];
			return pointer;
		}
	}
	return pointer;
}
//// even though getCustomer should be private, it helps autograding to make it public
bool Store::takeShipment(int productID, int quantity, double cost){
	if(getProduct(productID)!=nullptr){
		return getProduct(productID)->addShipment(quantity,cost);
	}
	else
		return false;
}
bool Store::sellProduct(int customerID, int productID, int quantity){
	if (getCustomer(customerID) == nullptr || getProduct(productID) == nullptr)
		return false;
	else{
		if(getProduct(productID)->reduceInventory(quantity)){
			double amount = getProduct(productID)->getPrice()*quantity;
				return getCustomer(customerID)->processPurchase(amount,*getProduct(productID));
		}else{
			return false;
		}
	}
}
bool Store::takePayment(int customerID, double amount){
	if (getCustomer(customerID) == nullptr)
		return false;
	else{
		return getCustomer(customerID)->processPayment(amount);
	}
}
void Store::outputProducts(std::ostream& os){
	 for (int i = 0; i < numProducts; ++i) {
	     Product* prod = products[i];
	        os<<*prod<<endl;
	    }
}
void Store::outputCustomers(std::ostream& os){
	for (int i = 0; i < numCustomers; ++i) {
		Customer* cust = customers[i];
		    os<<*cust<<endl;
		}
}
