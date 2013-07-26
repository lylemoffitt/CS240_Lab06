#ifndef IMDB_H
#define IMDB_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <algorithm>

class data
{
private:
	struct element
	{
		std::string Name;	// The name of the element (Title, Rating, Director, Actor)
		typedef element* MoviePtr;		// A pointer to the movie that this was in
		MoviePtr Link;

		element(std::string theName)
		{
			Name = theName;
			Link = nullptr;
		}
		~element()
		{
			delete Name;
			delete Link;
		}
	};
	 //there's error for the 'theName'
	typedef element* indexPtr;
	typedef std::vector<element> kindList; // The vector of each category list
	kindList Movie, Rating, Director, Actor, theMovies;
	int m,r,d,a, M;
	enum category
	{
		T = 1, //title
		R, //rating
		D, //director
		S //actors
	};
	int comma, //keeps track of placement in string for parseCommas fnt
		space; //keeps track of placement in string for parseSpaces fnt

public:
	data();		// Class constructor
	~data();	// Class destructor

	void Display();
	kindList getKind(category group);
	int SORT(std::vector<element> obj, std::string rawData);
	//friend bool operator< (vector<element>& lhs, vector<element>& rhs);
	std::string readFile(std::istream& FILE);
	std::string parseCommas(std::string rawData);
	std::string parseSpaces(std::string rawData);
	std::string parseActors(std::string rawData);
	std::string stringToupper(std::string rawData);
	bool addNew(std::string rawData); // IF parseCommas is run outside of this, then the param can be empty
	int binarySearch(kindList list, std::string search_term);
	bool getMatch(category group, std::string sub_string);
	void printMatch(element::MoviePtr titlePtr);

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
