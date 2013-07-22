#ifndef IMDB_H
#include "Lab06.h"
#endif //IMDB_H

#ifdef IMDB_H
using namespace std;

//class data
// Class constructor
	data::data()
	{



	}


	// Class destructor
	data::~data()
	{

	}

	int data::readFile(streambuf FILE)
	{
		string item;
		getline(FILE,item);
		parseCommas(item);
		// Takes in the initialization file as input.
		// Returns the length of the raw data string from the file, or zero on failure
		return 0;
	}

	string data::parseCommas(string rawData)
	{
		int i=0;
		string pos = rawData.at(i), temp;
		while(!rawData.end())
		{
			if(rawData.at(i) == ' ')
			{
				//temp = 
			}
			i++;
		}
		// Read raw data string up to first comma
		// Return string with leading/trailing whitespace stripped
		// Repeat until string.end()
		return 0;
	}


	bool data::addNew(string rawData) // IF parseCommas is run outside of this, then the param can be empty
	{
		// Iteratively read strips from the rawData
		/* For each category/strip read :
		 * 1) Search for spot in kindList for data element
		 * 2) Assign a kindList.element block for that strip
		 * 3) Link element.MoviePtr -> Movie
		 */
		// Return 0 if fail; 1 if success
		return 0;
	}

	data::indexPtr data::binarySearch(kindList list, string search_term)
	{
		// This could be potentially be replaced by std::binary_search from the algorithm library
		// .. though, i don't know how easily we can adapt that to our needs
		// Use std::string.compare() to determine break direction.
		// Use kindList.size() for START and END markers
		// Return an indexPtr to the first matching element or nullptr if not found
		return 0;
	}

	bool data::getMatch(category group, string sub_string)
	{
		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
		return 0;
	}

	void data::printMatch(element::MoviePtr titleName)
	{
		// Possibly print some header info
		// Print out titleName->Name()
	}


//class stopWatch // Time object

	stopWatch::stopWatch()			// Class Constructor
	{
		startTime = 0;
		stopTime = 0;
	}
	stopWatch::~stopWatch()			// Class destructor
	{
		delete &startTime;
		delete &stopTime;
	}

	void stopWatch::timeGo()		// Start the clock
	{
		startTime = time(NULL);
	}
	void stopWatch::timeStop()		// Start the clock
	{
		stopTime = time(NULL);
	}
	double stopWatch::duration()	// Return the total duration
	{
		// This probably needs to be formatted..
		return difftime(startTime,stopTime);
	}

#endif //IMDB_H
