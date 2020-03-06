#include <string>
#include "Drama.h"

Drama::Drama()
{

}

Drama::Drama(char thisType, int thisQuantity, string thisDirector, string thisTitle, int thisYear)
{
	thisType = type;
	thisQuantity = quantity;
	thisDirector = director;
	thisTitle = title;
	thisYear = year;
}

Drama::~Drama()
{
}

void Drama::setYear(int year)
{
	this->year = year;
}

int Drama::getYear()
{
	return this->year;
}

char Drama::getMovieType()
{
	return 'D';
}
