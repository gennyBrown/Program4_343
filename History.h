#define HISTORY_H
#ifdef HISTORY_H

class History::public Transactions {

public:
	History();	//default constructor
	//constructor, creates the history object
	History(char transactionType, char mediaType, Customer* customer);
	virtual ~History();	//overrides the parent destructor
	//overrides the parent function, executes the history object
	virtual void executeTransactions();
	//prints the history object
	friend ostream& operator << (ostream& const History&);
};

#endif // HISTORY_H
