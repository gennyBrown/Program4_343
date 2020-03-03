#define RETURN_H
#ifdef RETURN_H
#include "Transactions.h"


class Return::public Transactions {

public:
	
	Return();	//default constructor
	//constructor, creates the return object from the parent object
	Return(char transactionType, char mediaType, Customer* customer);
	virtual ~Return();	//destructor
	//overrides the parent class executeTransactions class and executes the return
	virtual void executeTransactions();
};

#endif // RETURN_H
