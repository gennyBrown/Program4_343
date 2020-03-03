#define INVENTORY_H
#ifdef INVENTORY_H

class Inventory::public Transactions {

	friend ostream& operator << (ostream& const Inventory&);
public:
	Inventory();	//default constructor
	//constructor, creates the inventory object from parent class
	Inventory(char transactionType, char mediaType, Customer* customer);			
	virtual ~Inventory();	//overrides the parent destructor
		//overrides the parent function, executes the inventory transaction
	virtual void executeTransactions();
	//prints the contents of inventory
	

};

#endif // INVENTORY_H
