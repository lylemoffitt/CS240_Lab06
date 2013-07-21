#ifndef IMDB_H
#define IMDB_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>

class data
{
private:
	struct element
	{
		std::string Name;	// The name of the element (Title, Rating, Director, Actor)
		typedef element* MoviePtr;		// A pointer to the movie that this was in
		element(std::string theName);
	};
	 //there's error for the 'theName'
	typedef element* indexPtr;
	typedef std::vector<element> kindList; // The vector of each category list
	enum category
	{
		T = 1, //title
		R, //rating
		D, //director
		S //actors
	};

public:
	data();		// Class constructor
	~data();	// Class destructor

	int readFile(std::streambuf FILE);
	std::string parseCommas(std::string rawData);
	bool addNew(std::string rawData); // IF parseCommas is run outside of this, then the param can be empty
	indexPtr binarySearch(kindList list, std::string search_term);
	bool getMatch(category group, std::string sub_string);
	void printMatch(element::MoviePtr titleName);

};

class stopWatch // Time object
{
private:
	time_t startTime;
	time_t stopTime;

public:
	stopWatch();			// Class Constructor
	~stopWatch();		// Class destructor
	
	void timeGo();		// Start the clock
	void timeStop();		// Start the clock
	double duration();	// Return the total duration

};

#endif // IMDB_H