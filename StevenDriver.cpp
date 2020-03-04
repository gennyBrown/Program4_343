

#include <iostream>
#include "Movie.h"
#include "Classic.h"

using namespace std;

int main() {
    Classic aClassic;

    aClassic.setReleaseDate("JULY2020");
    aClassic.getReleaseDate();

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


