/// ----------------------------- Classic.cpp ---------------------------------

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
#include<iostream>
#include "Classic.h"


// ----------------------Classic()--------------------------------
//
// Description
//	default constructor for classic object
//
// preconditions: the classic object was called by another function
// 
// postconditions: classic object was created
// ---------------------------------------------------------------------------
Classic::Classic() {
}
//end Classic()

// ------Classic(char, int, string, string, string, int, int)------------------
//
// Description
//	constructor with parameters for classic object
//
// preconditions: the classic object was called by another function 
// and valid parameters are passed to the function
// 
// postconditions: classic object was created
// ---------------------------------------------------------------------------
Classic::Classic(char thisType, int thisQuantity, string thisDirector, string 
	thisTitle, string thisActor, int thisReleaseMonth, int thisReleaseYear) {
	
	type = thisType;
	quantity = thisQuantity;
	director = thisDirector;
	title = thisTitle;
	actor = thisActor;
	releaseMonth = thisReleaseMonth;
	releaseYear = thisReleaseYear;
}
//end Classic(char, int, string, string, string, int, int)

// ------------------------~Classic()--------------------------------------
//
// Description
//	reallocats memory
//
// preconditions: the classic object instantiated by another function
// 
// postconditions: memory was reallocated
// ---------------------------------------------------------------------------
Classic::~Classic() {}
//end ~Classic()


// ------------------------setReleaseMonth(int thisReleaseMonth)---------------
//
// Description
//	sets the release month
//
// preconditions: valid releaseMonth is passed to the function
// 
// postconditions: releaseMonth is set
// ---------------------------------------------------------------------------
void Classic::setReleaseMonth(int thisReleaseMonth) {
	releaseMonth = thisReleaseMonth;
}
//end setReleaseMonth(int thisReleaseMonth)

// ------------------------getReleaseMonth()---------------------------------
//
// Description
//	gets the release month
//
// preconditions: valid releaseMonth set
// 
// postconditions: releaseMonth is returned
// ---------------------------------------------------------------------------
int Classic::getReleaseMonth() //returns the release date of the movie
{
	return releaseMonth;
}
//end getReleaseMonth()

// ------------------------setReleaseYear(int thisReleaseYear)---------------
//
// Description
//	sets the release year
//
// preconditions: valid releaseYear is passed to the function
// 
// postconditions: releaseYear is set
// ---------------------------------------------------------------------------
void Classic::setReleaseYear(int thisReleaseYear) {
	releaseYear = thisReleaseYear;
}
//end setReleaseYear(int thisReleaseYear)

// ------------------------getReleaseYear()------------------------------------
//
// Description
//	gets the release year
//
// preconditions: valid releaseYear is set
// 
// postconditions: releaseYear is returned
// ---------------------------------------------------------------------------
int Classic::getReleaseYear() //returns the release date of the movie
{
	return releaseYear;
}
//end getReleaseYear()

// ------------------------setActor(string thisName)---------------
//
// Description
//	sets the actor
//
// preconditions: valid actor is passed to the function
// 
// postconditions: actor is set
// ---------------------------------------------------------------------------
void Classic::setActor(string thisName)
{
	actor = thisName;
}
//end setActor(string thisName)

// ------------------------getActor()------------------------------------
//
// Description
//	gets the actor
//
// preconditions: valid actor is set
// 
// postconditions: actor is returned
// ---------------------------------------------------------------------------
string Classic::getActor() //returns the actor of the movie
{
	return actor;
}
//end getActor()

// ------------------------getMovieType()------------------------------------
//
// Description
//	gets the movie type
//
// preconditions: valid movieType is set
// 
// postconditions: movieType is returned
// ---------------------------------------------------------------------------
char Classic::getMovieType()	//returns the movie type 
{
	return type;
}
//end getMovieType()

// ------------------operator==(const Classic& classic) const-----------------
//
// Description
//	overloads the == operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Classic::operator==(const Classic& classic) const
{
	if (this->releaseYear == classic.releaseYear) {	//checks release date
		return true;
	}

	if (this->releaseMonth == classic.releaseMonth) {
		return true;
	}

	if (this->actor == classic.actor) {		//checks Acotr
		return true;
	}
	else {
		return false;
	}
}
//end operator==(const Classic& classic) const

// ------------------operator!=(const Classic& classic) const-----------------
//
// Description
//	overloads the != operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be equal or not equal
// ---------------------------------------------------------------------------
bool Classic::operator!=(const Classic& classic) const
{
	return !(operator==(classic));	//returns the opposite of ==
}
//end operator!=(const Classic& classic) const

// ------------------operator<(const Classic& classic) const-----------------
//
// Description
//	overloads the < operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be greater than 
// ---------------------------------------------------------------------------
bool Classic::operator<(const Classic& classic) const
{
	if (this->releaseMonth < classic.releaseMonth) {	//compares release date
		return true;
	}

	if (this->releaseYear < classic.releaseYear) {	//compares release date
		return true;
	}

	if (this->actor < classic.actor) {	//compares actor
		return true;
	}
	else {
		return false;
	}
}
//end operator<(const Classic& classic) const

// ------------------operator>(const Classic& classic) const-----------------
//
// Description
//	overloads the > operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be less than 
// ---------------------------------------------------------------------------
bool Classic::operator>(const Classic& classic) const
{
	if (this->releaseMonth > classic.releaseMonth) {	//compare release dates
		return true;
	}

	if (this->releaseYear > classic.releaseYear) {	//compare release dates
		return true;
	}
	if (this->actor > classic.actor) {	 //compare actors
		return true;
	}
	else {
		return false;
	}
}
//end operator>(const Classic& classic) const

// ------------------operator<=(const Classic& classic) const-----------------
//
// Description
//	overloads the <= operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be greater than or equal
// ---------------------------------------------------------------------------
bool Classic::operator<=(const Classic& classic) const
{
	if (this->releaseMonth <= classic.releaseMonth) {	//compare release dates
		return true;
	}
	if (this->releaseYear <= classic.releaseYear) {	//compare release dates
		return true;
	}
	if (this->actor <= classic.actor) {	//compare actor
		return true;
	}
	else {
		return false;
	}
}
//end operator<=(const Classic& classic) const

// ------------------operator>=(const Classic& classic) const-----------------
//
// Description
//	overloads the >= operator to be able to compare releaseYear, then
// releaseMonth, then actor
//
// preconditions: valid Classic is passed and valid Classic is being compared
// 
// postconditions: objects are determined to be less than or equal
// ---------------------------------------------------------------------------
bool Classic::operator>=(const Classic& classic) const
{
	if (this->releaseMonth >= classic.releaseMonth) {	//compare release dates
		return true;
	}

	if (this->releaseYear >= classic.releaseYear) {	//compare release dates
		return true;
	}

	if (this->actor >= classic.actor) {	//compare actor
		return true;
	}
	else {
		return false;
	}
}
//end operator>=(const Classic& classic) const

// ------------------operator=(const Classic& classic)-----------------
//
// Description
//	overloads the = operator to be able to set one object equal to the other
//
// preconditions: valid Classic is passed and valid Classic is being set equal
// 
// postconditions: objects are equal to each other
// ---------------------------------------------------------------------------
Classic& Classic::operator=(const Classic& classic)
{
	if (*this != classic) {
		this->director = classic.director;
		this->title = classic.title;
		this->releaseMonth = classic.releaseMonth;
		this->releaseYear = classic.releaseYear;
		this->quantity = classic.quantity;
		this->type = classic.type;
		this->actor = actor;
	}
	return *this;
}
//end operator=(const Classic& classic)

// ------------------operator<<(ostream& output, Classic& nd)-----------------
//
// Description
//	overloads the << operator to be able to print a classic object
//
// preconditions: valid Classic is passed
// 
// postconditions: object is printed
// ---------------------------------------------------------------------------
ostream& operator<<(ostream& output, Classic& nd) {
	output << nd.type << ", " << nd.quantity << ", " <<
		nd.director << ", " << nd.title << ", " << nd.releaseMonth << " "
		<<nd.releaseYear << " " << nd.actor << endl;
	return output;
}
//end operator<<(ostream& output, Classic& nd)