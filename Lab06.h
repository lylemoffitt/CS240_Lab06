//header file
#ifndef IMDB_H
#define IMDB_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <boost/chrono.hpp> //Apparently it's part of the boost library..

class data
{
private:
	struct element
	{
		std::string Name;	// The name of the element (Title, Rating, Director, Actor)
		typedef element* MoviePtr;		// A pointer to the movie that this was in
		MoviePtr link;
		element(std::string theName)
		{
			Name = theName;
			link = nullptr;
		}
		~element();	// Do we need an element destructor?

	};
	//there's error for the 'theName'
	typedef element::MoviePtr indexPtr; //Changed from element*
	typedef std::vector<element> kindList; // The vector of each category list
	typedef kindList * kindPtr;// Reference pointer to a kindList
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
	bool compareElem(element ONE, element TWO);
	void sortElem();
	friend bool operator< (const element& ONE, const element& TWO);
	std::string trimDelim(std::string input, std::string delimz);
	std::string readFile(std::ifstream& FILE);
	std::string parseCommas(std::string rawData);
	std::string parseSpaces(std::string rawData);
	std::string parseActors(std::string rawData);
	std::string stringToupper(std::string rawData);
	bool addNew(std::string rawData); // IF parseCommas is run outside of this, then the param can be empty
	int binarySearch(kindList list, std::string search_term);
	bool getMatch();
	void fetch();
	bool getMatches(std::string lineStr);
	kindList getKind(char group);
	void getKind(char group, int found, std::string keyword);
	void findRating(std::string firstBound, std::string search, int found);

};

class stopWatch // Time object
{
private:
	long startTime;
	long stopTime;

public:
	stopWatch();			// Class Constructor
	~stopWatch();		// Class destructor

	void timeGo();		// Start the clock
	void timeStop();		// Start the clock
	long duration();	// Return the total duration

};

#endif // IMDB_H
