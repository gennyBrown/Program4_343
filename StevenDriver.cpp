

#include <iostream>
#include "Classic.h"
#include "Drama.h"
#include "MovieBST.h"

using namespace std;

int main() {
    Classic aClassic;

    Drama aDrama;
    
    Movie mov;

    MovieBST movBST;



    aClassic.setReleaseDate("JULY2020");
    aClassic.getReleaseDate();

   Movie amovie;

   Movie anotherMovie("Genny", "MOVIE TITLE", 'F', 10, 1990);

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

   amovie.setDirector("Mowgli");
   movBST.insert(amovie);
   movBST.insert(anotherMovie);
   movBST.printTree(movBST.root);
   

   cout << amovie.coutQuantity << endl;

   cout << amovie.getYear() << endl;

}


