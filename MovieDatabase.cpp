/// ----------------------------- MovieDatabase.cpp ---------------------------

// Steven Bollman & Genny Brown CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/14/2020

// ----------------------------------------------------------------------------

// Purpose - This program provides destructor and getters for all three BST
// types
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#include "MovieDatabase.h"
// ----------------------~MovieDatabase()--------------------------------
//
// Description
//	destructor for MovieDatabase object
//
// preconditions: MovieDatabase object created
// 
// postconditions: memory reallocated
// ---------------------------------------------------------------------------
MovieDatabase::~MovieDatabase()
{
}
//end ~MovieDatabase()

// ----------------------getComedies()--------------------------------
//
// Description
//	getter for comedyBST object
//
// preconditions: ComedyBST exists
// 
// postconditions: ComedyBST returned
// ---------------------------------------------------------------------------
MovieBST MovieDatabase::getComedies()
{
	return MovieBST();
}
//end getComedies()

// ----------------------getDrama()--------------------------------
//
// Description
//	getter for DramaBST object
//
// preconditions: DramaBST exists
// 
// postconditions: DramaBST returned
// ---------------------------------------------------------------------------
MovieBST MovieDatabase::getDramas()
{
	return MovieBST();
}
//end getDramas()

// ----------------------getClassics()--------------------------------
//
// Description
//	getter for ClassicsBST object
//
// preconditions: ClassicsBST exists
// 
// postconditions: ClassicsBST returned
// ---------------------------------------------------------------------------
MovieBST MovieDatabase::getClassics()
{
	return MovieBST();
}
//end getClassics()