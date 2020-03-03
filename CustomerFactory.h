#define CUSTOMER_FACTORY_H
#ifdef CUSTOMER_FACOTRY_H

class CustomerFactory {

public:
	CustomerFactory();	//constructor
	virtual ~CustomerFactory();	//destructor
//reads the file and creates the customer
	void storeCustomer(ifstream& input);
};

#endif // CUSTOMER_FACOTRY_H
