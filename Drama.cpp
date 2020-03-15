/// ----------------------------- Drama.cpp ---------------------------------

// Steven Bollman & Genny Brown CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/14/2020

// ----------------------------------------------------------------------------

// Purpose - This program provides constructors, destructor, getters and 
// setters for the movie class. The getters and setters provided for the 
// director, title, quantity, movietype, and year. Operator overloads for
// ==, !=, <, >, <=, >=, =, and << are defined.
// ----------------------------------------------------------------------------
#include <string>
#include "Drama.h"
#include <iostream>

// ----------------------Drama()--------------------------------
//
// Description
//	default constructor for drama object
//
// preconditions: the drama object was called by another function
// 
// postconditions: drama object was created
// ---------------------------------------------------------------------------
Drama::Drama()
{

}
//end Drama()

// ------Drama(char, int, string, string, int, int)------------------
//
// Description
//	constructor with parameters for drama object
//
// preconditions: the drama object was called by another function 
// and valid parameters are passed to the function
// 
// postconditions: drama object was created
// ---------------------------------------------------------------------------
Drama::Drama(char thisType, int thisQuantity, string thisDirector, string thisTitle, int thisYear)
{
	thisType = type;
	thisQuantity = quantity;
	thisDirector = director;
	thisTitle = title;
	thisYear = year;
}
//end Drama(char, int, string, string, int)

// ------------------------~Drama()--------------------------------------
//
// Description
//	reallocats memory
//
// preconditions: the drama object instantiated by another function
// 
// postconditions: memory was reallocated
// ---------------------------------------------------------------------------
Drama::~Drama()
{
}
//end ~Drama()

// ------------------------setYear(int year)--------------------------------------
//
// Description
//	sets the year 
//
// preconditions: a valid year is passed to the function
// 
// postconditions: year is set
// ---------------------------------------------------------------------------
void Drama::setYear(int year)
{
	this->year = year;
}
//end setYear(int year)

// ------------------------getYear()--------------------------------------
//
// Description
//	gets the year 
//
// preconditions: a valid year is set
// 
// postconditions: year is returned
// ---------------------------------------------------------------------------
int Drama::getYear()
{
	return this->year;
}
//end getYear()

// ------------------------getMovieType()------------------------------------
//
// Description
//	gets the movie type
//
// preconditions: valid movieType is set
// 
// postconditions: movieType is returned
// ---------------------------------------------------------------------------
char Drama::getMovieType()
{
	return 'D';
}
//end getMovieType()

// ------------------operator==(const Drama& drama) const-----------------
//
// Description
//	overloads the == operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Drama::operator==(const Drama& drama) const
{
	if (this->director == drama.director) {	//checks directors
		return true;
	}
	if (this->title == drama.title) {		//checks titles
		return true;
	}
	else {
		return false;
	}
}
//end operator==(const Drama& drama) const

// ------------------operator!=(const Drama& drama) const-----------------
//
// Description
//	overloads the != operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Drama::operator!=(const Drama& drama) const
{
	return !(operator==(drama));	//returns the opposite of ==
}
//end operator!=(const Drama& drama) const

// ------------------operator<(const Drama& drama) const-----------------
//
// Description
//	overloads the < operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be greater than 
// ---------------------------------------------------------------------------
bool Drama::operator<(const Drama& drama) const
{
	if (this->director < drama.director) {
		return true;
	}
	if (this->title < drama.title) {
		return true;
	}
	else {
		return false;
	}
}
//end operator<(const Drama& drama) const

// ------------------operator>(const Drama& drama) const-----------------
//
// Description
//	overloads the > operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be less than 
// ---------------------------------------------------------------------------
bool Drama::operator>(const Drama& drama) const
{
	if (this->director > drama.director) {	//compare directors
		return true;
	}
	if (this->title > drama.title) {	//compare titles
		return true;
	}
	else {
		return false;
	}
}
//end operator>(const Drama& drama) const


// ------------------operator<=(const Drama& drama) const-----------------
//
// Description
//	overloads the <= operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be greater than or equal
// ---------------------------------------------------------------------------
bool Drama::operator<=(const Drama& drama) const
{
	if (this->director <= drama.director) {	//compare directors
		return true;
	}
	if (this->title <= drama.title) {	//compare titles
		return true;
	}
	else {
		return false;
	}
}
//end operator<=(const Drama& drama) const

// ------------------operator>=(const Drama& drama) const-----------------
//
// Description
//	overloads the >= operator to be able to compare director, then title
//
// preconditions: valid drama is passed and valid drama is being compared
// 
// postconditions: objects are determined to be less than or equal
// ---------------------------------------------------------------------------
bool Drama::operator>=(const Drama& drama) const
{
	if (this->director >= drama.director) {	//compare directors
		return true;
	}
	if (this->title >= drama.title) {	//titles
		return true;
	}
	else {
		return false;
	}
}
//end operator>=(const Drama& drama) const

// ------------------operator=(const Drama& drama)-----------------
//
// Description
//	overloads the = operator to be able to set one object equal to the other
//
// preconditions: valid drama is passed and valid drama is being set equal
// 
// postconditions: objects are equal to each other
// ---------------------------------------------------------------------------
Drama& Drama::operator=(const Drama& drama)
{
	if (*this != drama) {
		this->director = drama.director;
		this->title = drama.title;
		this->year = drama.year;
		this->quantity = drama.quantity;
		this->type = drama.type;
	}
	return *this;
}
//end operator=(const Drama& drama)

// ------------------operator<<(ostream& output, Drama& nd)-----------------
//
// Description
//	overloads the << operator to be able to print a drama object
//
// preconditions: valid drama is passed
// 
// postconditions: object is printed
// ---------------------------------------------------------------------------
ostream& operator<<(ostream& output, Drama& nd){
	output << nd.type << ", " << nd.quantity <<  ", " <<
		nd.director <<  ", " << nd.title <<  ", "  << nd.year << endl;
	return output;
}
//end operator<<(ostream& output, Drama& nd)