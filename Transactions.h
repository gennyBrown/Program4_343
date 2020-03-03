#define TRANSACTIONS_H
#ifdef TRANSACTIONS_H
#include "Customer.h"
using namespace std;

class Transactions {

public:
	Transactions();	//constructor
	virtual ~Transactions();	//destructor
//function to execute transactions, will be overridden by derived classes
	virtual void executeTransactions() const = 0;
	virtual void setTransactions(char transactionTypes);	//sets the transactions

protected:
	char transactionType;	//stores the transaction type
	char mediaType;		//stored the media type
	Customer* customer;	//stores a pointer to the customer object

};

#endif // TRANSACTIONS_
