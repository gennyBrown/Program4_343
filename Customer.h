#define CUSTOMER_H
#ifdef CUSTOMER_H

class Customer {

Public:
	Customer();	//default constructor
//creates the customer 
	Customer(int id, string firstName, string lastName);
	~Customer();	//destructor
Protected:
	int id;		//holds the customer id number
	string firstName;	//holds customer first name
	string lastName;	//holds customer last name

	);

#endif // CUSTOMER_H
