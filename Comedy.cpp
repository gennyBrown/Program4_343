/// ----------------------------- Comedy.cpp ---------------------------------

// Steven Bollman & Genny Brown CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/3/2020

// ----------------------------------------------------------------------------

// Purpose - This program provides constructors, destructor, getters and 
// setters for the movie class. The getters and setters provided for the 
// director, title, quantity, movietype, and year. Operator overloads for
// ==, !=, <, >, <=, >=, =, and << are defined.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "Comedy.h"

// ----------------------Comedy()--------------------------------
//
// Description
//	default constructor for comedy object
//
// preconditions: the comedy object was called by another function
// 
// postconditions: comedy object was created
// ---------------------------------------------------------------------------
Comedy::Comedy()
{

}
//end Comedy()

// ------Comedy(char, int, string, string, int, int)------------------
//
// Description
//	constructor with parameters for comedy object
//
// preconditions: the comedy object was called by another function 
// and valid parameters are passed to the function
// 
// postconditions: comedy object was created
// ---------------------------------------------------------------------------
Comedy::Comedy(char type, int quantity, string director, string title, int year)
{
	type = type;
	quantity = quantity;
	director = director;
	title = title;
	year = year;
}
//end Comedy(char, int, int, string, string, int)

// ------------------------~Comedy()--------------------------------------
//
// Description
//	reallocats memory
//
// preconditions: the classic object instantiated by another function
// 
// postconditions: memory was reallocated
// ---------------------------------------------------------------------------
Comedy::~Comedy()
{
}
//end ~Comedy()

// ------------------------setYear(int year)--------------------------------------
//
// Description
//	sets the year 
//
// preconditions: a valid year is passed to the function
// 
// postconditions: year is set
// ---------------------------------------------------------------------------
void Comedy::setYear(int year)
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
int Comedy::getYear()
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
char Comedy::getMovieType()
{
	return 'F';
}
//end getMovieType()

// ------------------operator==(const Comedy& comedy) const-----------------
//
// Description
//	overloads the == operator to be able to compare title, then year
//
// preconditions: valid Comedy is passed and valid Comedy is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Comedy::operator==(const Comedy& comedy) const
{
	if (this->title == comedy.title) {	//checks titles
		return true;
	}
	if (this->year == comedy.year) {		//checks years
		return true;
	}
	else {
		return false;
	}
}
//end operator==(const Comedy& comedy) const

// ------------------operator!=(const Comedy& comedy) const-----------------
//
// Description
//	overloads the != operator to be able to compare title, then year
//
// preconditions: valid Comedy is passed and valid Comedy is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Comedy::operator!=(const Comedy& comedy) const
{
	return !(operator==(comedy));	//returns the opposite of ==
}
//end operator!=(const Comedy& comedy) const

// ------------------operator<(const Comedy& comedy) const-----------------
//
// Description
//	overloads the < operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Comedy is passed and valid Comedy is being compared
// 
// postconditions: objects are determined to be greater than 
// ---------------------------------------------------------------------------
bool Comedy::operator<(const Comedy& comedy) const
{
	if (this->title < comedy.title) {	//compares titles
		return true;
	}
	if (this->year < comedy.year) {	//compares years
		return true;
	}
	else {
		return false;
	}
}
//end operator<(const Comedy& comedy) const

// ------------------operator>(const Comedy& comedy) const-----------------
//
// Description
//	overloads the > operator to be able to compare title, then year
//
// preconditions: valid Comedy is passed and valid Comedyis being compared
// 
// postconditions: objects are determined to be less than 
// ---------------------------------------------------------------------------
bool Comedy::operator>(const Comedy& comedy) const
{
	if (this->title > comedy.title) {	//compare titles
		return true;
	}
	if (this->year > comedy.year) {	 //compare years
		return true;
	}
	else {
		return false;
	}
}
//end operator>(const Comedy& comedy) const

// ------------------operator<=(const Comedy& comedy) const-----------------
//
// Description
//	overloads the <= operator to be able to compare title
//
// preconditions: valid Comedy is passed and valid Comedy is being compared
// 
// postconditions: objects are determined to be greater than or equal
// ---------------------------------------------------------------------------
bool Comedy::operator<=(const Comedy& comedy) const
{
	if (this->title <= comedy.title) {	//compare titles
		return true;
	}
	if (this->year <= comedy.year) {	//compare years
		return true;
	}
	else {
		return false;
	}
}
//end operator<=(const Comedy& comedy) const

// ------------------operator>=(const Comedy& comedy) const-----------------
//
// Description
//	overloads the >= operator to be able to compare title, then year
//
// preconditions: valid Comedy is passed and valid Comedy is being compared
// 
// postconditions: objects are determined to be less than or equal
// ---------------------------------------------------------------------------
bool Comedy::operator>=(const Comedy& comedy) const
{
	if (this->title >= comedy.title) {		//compare titles
		return true;
	}
	if (this->year >= comedy.year) {	//compare years
		return true;
	}
	else {
		return false;
	}
}
//end operator>=(const Comedy& comedy) const

// ------------------operator=(const Comedy& comedy)-----------------
//
// Description
//	overloads the = operator to be able to set one object equal to the other
//
// preconditions: valid Comedy is passed and valid Comedy is being set equal
// 
// postconditions: objects are equal to each other
// ---------------------------------------------------------------------------
Comedy& Comedy::operator=(const Comedy& comedy)
{
	if (*this != comedy) {
		this->director = comedy.director;
		this->title = comedy.title;
		this->year = comedy.year;
		this->quantity = comedy.quantity;
		this->type = comedy.type;
	}
	return *this;
}
////end operator=(const Comedy& comedy)

// ------------------operator<<(ostream& output, Comedy& nd)-----------------
//
// Description
//	overloads the << operator to be able to print a comedy object
//
// preconditions: valid Comedy is passed
// 
// postconditions: object is printed
// ---------------------------------------------------------------------------
ostream& operator<<(ostream& output, Comedy& nd) {
	output << nd.type << ", " << nd.quantity << ", " <<
		nd.director << ", " << nd.title << ", " << nd.year << endl;
	return output;
}
//end operator<<(ostream& output, Comedy& nd)