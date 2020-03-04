#include <string>
#include "Comedy.h"

Comedy::Comedy()
{

}

Comedy::Comedy(char type, int quantity, string director, string title, int year)
{
	type = type;
	quantity = quantity;
	director = director;
	title = title;
	year = year;
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
