

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

  

  // movBST.printTree(movBST.root);


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

   movBST.insert(amovie);
   movBST.printTree(movBST.root);

}


