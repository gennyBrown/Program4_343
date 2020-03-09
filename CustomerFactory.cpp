#include "CustomerFactory.h"
#include "Customer.h"
#include <string>
#include <iostream>


CustomerFactory::CustomerFactory()
{
	accountNumber = 0;
	firstName = "";
	lastName = "";
}

CustomerFactory::~CustomerFactory()
{
}

void CustomerFactory::storeCustomer(ifstream& input)
{
	while (!input.eof()) {	//checks to see if at end of file
		input >> accountNumber;			//reads customer account number
		if (accountNumber) {		//if account number
			input >> lastName;
			input >> firstName;
			Customer(accountNumber, firstName, lastName);		//creates the customer object
		}
		else {	//if incorrect formatting
			cout << "Incorrect input formatting" << endl;
		}
	}//end while loop
}