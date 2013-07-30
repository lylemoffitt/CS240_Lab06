#ifndef LAB06_H
#define LAB06_H

#include <vector>
#include <string>
#include <iostream>
#include <ios>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>

class data
{
private:
	
	struct element
	{
		std::string Name;
		//double Rate;// The name of the element (Title, Rating, Director, Actor)
		typedef element* MoviePtr;		// A pointer to the movie that this was in
		MoviePtr link;
		element(std::string theName)
		{
			Name = theName;
			link = nullptr;
		}
		/*element(double theRate)
		{
			Rate = theRate;
			link = nullptr;
		}*/
	};
	typedef std::vector<element> kindList;
	typedef element* indexPtr;
	 // The vector of each category list
	kindList Movie, Director, Actor, Rating, theMovies;
	std::vector<std::string> vecTemp;
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
	//friend bool operator< (const element& rhs);
	std::string readFile(std::ifstream& FILE);
	std::string parseCommas(std::string rawData);
	std::string parseSpaces(std::string rawData);
	std::string parseActors(std::string rawData);
	std::string stringToupper(std::string rawData);
	bool addNew(std::string rawData); 
	int binarySearch(kindList list, std::string search_term);
	int data::binarySearch(kindList list, std::string search_term, std::string last_term);
	bool getMatch();
	kindList getKind(char group);
	void getKind(char group, int found, std::string keyword);
	void findRating(std::string firstBound, std::string search, std::string endBound, int found);
	bool getMatches(std::string lineStr);
	std::string getStarMatch(std::string search);
	void data::getMatchesAux();
	void fetch();
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