

#include <iostream>
#include "Movie.h"

using namespace std;

int main() {

   Movie amovie;
   
   amovie.setDirector("Steven");
   cout << amovie.getDirector() << endl;


   amovie.setTitle("Atitle");
   cout << amovie.getTitle() << endl;;

   amovie.setQuantity(100);
   cout << amovie.getQuantity() << endl;

   amovie.setMovieType('D');
   cout << amovie.getMovieType() << endl;

   amovie.setYear(2006);
   cout << amovie.getYear() << endl;

}


