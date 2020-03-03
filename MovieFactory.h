#define MOVIE_FACTORY_H
#ifdef MOVIE_FACTORY_H
#include <fstream>
using namespace std;


class MovieFactory {
public:
	MovieFactory();
	virtual ~MovieFactory();

	void storeMovie(ifstream& input);
	bool makeMovie(char movieType);
};

#endif