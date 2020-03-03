#define TRANSACTION_FACTORY_H
#ifdef TRANSACTION_FACTORY_H
#include <fstream>
#include <queue>
#include "Transactions.h"
using namespace std;

class TransactionFactory {

public:
	TransactionFactory();		//constructor
	virtual ~TransactionFactory();	//destructor
	void storeTransaction(ifstream& input);	//reads the file and calls make function
	//takes in the transaction type and creates the correct transaction
	bool makeTransaction(char transactionType);

protected:
	//stores the transactions as they are read from the file
	queue<Transactions> transactionQueue;
};

#endif // TRANSACTION_FACTORY_
