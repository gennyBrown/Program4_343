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
		 
