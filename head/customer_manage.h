#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <vector>
#include <string>
#include "customer.h"

using namespace std;


class customerManager {

public:

	vector<Customer> customers; // NEW 외부 클래스의 접근을 위해 접근권한 private->public으로 이동

	void loadFromCSV(const string& filename); 
	void saveToCSV(const string& filename) const; 

	void addCustomer();
	void modifyCustomer(); 
	void deleteCustomer(); 

 	Customer* getCustomerById(int id);

	void viewCustomer() const; 
};

#endif // !CUSTOMER_MANAGER_H