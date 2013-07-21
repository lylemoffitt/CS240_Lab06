#ifndef IMDB_H
#define IMDB_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>


class data
{
private:
	struct element
	{
		std::string Name;	// The name of the element (Title, Rating, Director, Actor)
		typedef element * MoviePtr;		// A pointer to the movie that this was in
	};
	typedef element * indexPtr;
	typedef std::vector<element> kindList; // The vector of each category list
	enum category
	{
		T = "Title",
		R = "Rating",
		D = "Director",
		S = "Stars"
	};

public:
	data();		// Class constructor
	~data();	// Class destructor
	int readFile(std::streambuf FILE)
	{
		// Takes in the initialization file as input.
		// Returns the length of the raw data string from the file, or zero on failure
	}

	std::string parseCommas(std::string rawData)
	{
		// Read raw data string up to first comma
		// Return string with leading/trailing whitespace stripped
		// Repeat until string.end()
	}

	bool addNew(std::string rawData) // IF parseCommas is run outside of this, then the param can be empty
	{
		// Iteratively read strips from the rawData
		/* For each category/strip read :
		 * 1) Search for spot in kindList for data element
		 * 2) Assign a kindList.element block for that strip
		 * 3) Link element.MoviePtr -> Movie
		 */
		// Return 0 if fail; 1 if success
	}

	indexPtr binarySearch(kindList list, std::string search_term)
	{
		// This could be potentially be replaced by std::binary_search from the algorithm library
		// .. though, i don't know how easily we can adapt that to our needs
		// Use std::string.compare() to determine break direction.
		// Use kindList.size() for START and END markers
		// Return an indexPtr to the first matching element or nullptr if not found
	}

	bool getMatch(category group, std::string sub_string)
	{
		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
	}

	void printMatch(element::MoviePtr titleName)
	{
		// Possibly print some header info
		// Print out titleName->Name()
	}

}

class stopWatch // Time object
{
private:
	time_t startTime;
	time_t stopTime;

public:
	stopWatch()			// Class Constructor
	{
		startTime = 0;
		stopTime = 0;
	}
	~stopWatch()		// Class destructor
	{
		delete startTime;
		delete stopTime;
	}

	void timeGo()		// Start the clock
	{
		startTime = time(NULL);
	}
	void timeStop()		// Start the clock
	{
		stopTime = time(NULL);
	}
	double duration()	// Return the total duration
	{
		// This probably needs to be formatted..
		return difftime(startTime,stopTime);
	}
};

#endif // IMDB_H
