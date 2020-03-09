#ifndef CUSTOMER_FACOTRY_H
#define CUSTOMER_FACTORY_H
#include "Customer.h"
#include <fstream>
using namespace std;

class CustomerFactory {

public:
	CustomerFactory();	//constructor
	~CustomerFactory();	//destructor
//reads the file and creates the customer
	void storeCustomer(ifstream& input);

	string firstName, lastName;
	int accountNumber;



};

#endif // CUSTOMER_FACOTRY_H