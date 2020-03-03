#define CUSTOMER_DATABASE_H
#ifdef CUSTOMER_DATABASE_H
#include "Transactions.h"

class CustomerDatabase {

public:
	struct ListNode {
		Transaction data;	//holds the transaction data
		ListNode* next;     //points to the next item in the list
	};
	
	ListNode* head;	//holds the head pointer for the list
	ListNode* array[100];	//each index holds the history of each customer
	CustomerDatabase();	//constructor
	virtual ~CustomerDatabase();	//destructor
		//hashes the customer id number and stores it in the array
	int hashFunction(int key);
	void retrieve(int key); // goes to key and prints out list

private:
	
	ListNode* tail;       //holds the tail of the list to be able to insert more efficiently
	bool insert(); // always inserts to the tail

};
#endif // CUSTOMER_DATABASE_H
