#include<iostream>
#include "Classic.h"


Classic::Classic() {
}		//default constructor 

//constructor with parameters for use in the factory
Classic::Classic(char thisType, int thisQuantity, string thisDirector, string thisTitle,
	string thisActor, string thisReleaseDate) {
	type = thisType;
	quantity = thisQuantity;
	director = thisDirector;
	title = thisTitle;
	actor = thisActor;
	releaseDate = thisReleaseDate;
}
Classic::~Classic() {}		//destructor

//sets the release date of the movie
void Classic::setReleaseDate(string thisReleaseDate) {
	releaseDate = thisReleaseDate;
}
string Classic::getReleaseDate() //returns the release date of the movie
{
	return releaseDate;
}

void Classic::setActor(string thisName) //sets the actor of the movie
{
	actor = thisName;
}


string Classic::getActor() //returns the actor of the movie
{
	return actor;
}
char Classic::getMovieType()	//returns the movie type 
{
	return type;
}

bool Classic::operator==(const Classic& classic) const
{
	if (this->releaseDate == classic.releaseDate) {	//checks release date
		return true;
	}
	if (this->actor == classic.actor) {		//checks Acotr
		return true;
	}
	else {
		return false;
	}
}

bool Classic::operator!=(const Classic& classic) const
{
	return !(operator==(classic));	//returns the opposite of ==
}

bool Classic::operator<(const Classic& classic) const
{
	if (this->releaseDate < classic.releaseDate) {	//compares release date
		return true;
	}
	if (this->actor < classic.actor) {	//compares actor
		return true;
	}
	else {
		return false;
	}
}

bool Classic::operator>(const Classic& classic) const
{
	if (this->releaseDate > classic.releaseDate) {	//compare release dates
		return true;
	}
	if (this->actor > classic.actor) {	 //compare actors
		return true;
	}
	else {
		return false;
	}
}

bool Classic::operator<=(const Classic& classic) const
{
	if (this->releaseDate <= classic.releaseDate) {	//compare release dates
		return true;
	}
	if (this->actor <= classic.actor) {	//compare actor
		return true;
	}
	else {
		return false;
	}
}

bool Classic::operator>=(const Classic& classic) const
{
	if (this->releaseDate >= classic.releaseDate) {	//compare release dates
		return true;
	}
	if (this->actor >= classic.actor) {	//compare actor
		return true;
	}
	else {
		return false;
	}
}

Classic& Classic::operator=(const Classic& classic)
{
	if (*this != classic) {
		this->director = classic.director;
		this->title = classic.title;
		this->releaseDate = classic.releaseDate;
		this->quantity = classic.quantity;
		this->type = classic.type;
	}
	return *this;
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, Classic& nd) {
	output << nd.type << ", " << nd.quantity << ", " <<
		nd.director << ", " << nd.title << ", " << nd.releaseDate << endl;
	return output;
}