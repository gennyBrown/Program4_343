#define NODEDATA_H
#ifdef NODEDATA_H
using namespace std;

class NodeData {
	//prints Nodedata
	friend ostream& operator<<(ostream&, const NodeData&);

public:
	NodeData();     //constructor
	~NodeData();	//destructor
	NodeData(const Movie&);   //constructor with parameters
	NodeData(const NodeData&);   	//copy constructor
	NodeData& operator=(const NodeData&);	//assignment operator overload

	bool setData(istream&);	//sets the data in the node
	bool operator==(const NodeData&) const;	//equal operator overload
	bool operator!=(const NodeData&) const;	//not equal operator overload
	bool operator<(const NodeData&) const;	//less-than operator overload
	bool operator>(const NodeData&) const;	//greater-than operator overload
//less-than-or-equal- to operator overload
	bool operator<=(const NodeData&) const;
	//greater-than-or-equal- to operator overload	
	bool operator>=(const NodeData&) const;

private:
	Movie data;	//holds the Movie information in the node
};
#endif