#include <string>
#include "Comedy.h"

Comedy::Comedy()
{

}

Comedy::Comedy(char thisType, int thisQuantity, string thisDirector, string thisTitle, int thisYear)
{
	thisType = type;
	thisQuantity = quantity;
	thisDirector = director;
	thisTitle = title;
	thisYear = year;
}

Comedy::~Comedy()
{
}

void Comedy::setYear(int year)
{
	this->year = year;
}

int Comedy::getYear()
{
	return this->year;
}

char Comedy::getMovieType()
{
	return 'F';
}
