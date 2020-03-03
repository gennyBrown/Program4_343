#define BORROW_H
#ifdef BORROW_H
#include "Transactions.h"
#include "Customer.h"

using namespace std;

class Borrow::public Transactions {

public:
	Borrow();	//default constructor
	//constructor to create the borrow transaction from the parent class
	Borrow(char transactionType, char mediaType, Customer* customer);
	virtual ~Borrow();	//destructor
//overrides the parent class executeTransactions class and executes the borrow
	virtual void executeTransactions();
};

#endif // BORROW_
