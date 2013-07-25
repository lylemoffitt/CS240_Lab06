#include "Lab06.h"
using namespace std;

//class data
// Class constructor
  data::data()
	{
		comma = 0; //initialize counters -Tania
		space = 0;
		m=0;
		d=0;
		r=0;
		a=0;
		M=0;

	}


	// Class destructor
	data::~data()
	{

	}
	//takes in the file and reads the first line and returns the string -Tania
	string data::readFile(istream& FILE)
	{
		string item;
		while(!FILE.eof())
		{
			getline(FILE, item);
			addNew(item);
		}
		// Takes in the initialization file as input.
		// Returns the length of the raw data string from the file, or zero on failure
		return item;
	}
	//takes string from readFile and parses it by commas -Tania
	//checks to see next charachter in string is a space if it is it fixes comma
	//then it copies the strung into a temp up until the first comma
	//then it increase the count and returns the parsed string
	string data::parseCommas(string rawData)
	{
		if(rawData.at(comma) == ' ')
			comma += 1;
		else if(rawData.at(comma) == '\0')
		{
			comma = 0;
			return "0";
		}
		string temp, TEMP;
		//int pos = rawData.at(comma);
		while(rawData.at(comma) != ',' && rawData.at(comma) != '\0')
		{
			TEMP = rawData.at(comma);
			temp.append(TEMP);
			comma++;
		}
		comma++;
		return temp;
		/*if(rawData.at(comma) == '\0')
			return "0";
		else
			return temp;
		/*
		if(rawData.at(amount) == ' ')
			rawData.erase(pos,amount+1);
		else
			rawData.erase(pos,amount);*/
		// Read raw data string up to first comma
		// Return string with leading/trailing whitespace stripped
		// Repeat until string.end()
	}
	//takes in string parsed by the parseComma fnt and parses it by spaces -Tania
	//this does the exact same thing as parseComma except it parses it at the spaces
	string data::parseSpaces(string rawData)
	{
		if(rawData.at(space) == ' ')
			space += 1;
		else if(rawData.at(space) == '\0')
		{
			space = 0;
			return "0"; //or we can say while string.at(string.length()) != comma in addnew function
		}
		string temp, TEMP;
		while(rawData.at(space) != ' ' && rawData.at(space) != ',' && rawData.at(comma) != '\0')
		{
			TEMP = rawData.at(comma);
			temp.append(TEMP);
			comma++;
		}
		//rawData.erase(pos,i);
		space++;
		return temp;
	}

	//parseSpaces(string), parseCommas(string), readFile(istream)
	//This doesn't make much sense right now
	//I'm going to work on it more in VS to make sure what I'm thinking is legal...
	//here's what I have so far -Tania
	string data::parseActors(string rawData)
	{
		string temp, TEMP=0;

		while(rawData.at(space) != '\0')
		{
			TEMP = rawData.at(comma);
			temp.append(TEMP);
			comma++;
		}
		return temp;
	}

	string data::stringToupper(string rawData)
	{
		int i=0;
		while(rawData.at(i) != '\0')
		{
			rawData.at(i) = toupper(rawData.at(i));
			i++;
		}
		return rawData;
	}


	bool data::addNew(string rawData) // IF parseCommas is run outside of this, then the param can be empty
	{
		string movie, rating, director, actors, bySpace;

		movie = parseCommas(rawData);
		theMovies.push_back(element(movie));
		Movie[m].link = theMovies[M].link;
		m++;

		rating = parseCommas(rawData);
		director = parseCommas(rawData);
		actors = parseActors(rawData);

		bySpace = parseSpaces(movie);
		while(bySpace != "0")
		{
			//toupper byspace
			Movie.push_back(element(bySpace));
			Movie[m].link = theMovies[M].link;
			m++;
			bySpace = parseSpaces(movie);
			//build movie vector
			//set pointers
		}

		bySpace = parseSpaces(director);
		while(bySpace != "0")
		{
			//toupper byspace
			Director.push_back(element(bySpace));
			Director[d].link = theMovies[M].link;
			d++;
			bySpace = parseSpaces(director);
			//build director vector
			//set pointers
		}

		bySpace = parseSpaces(actors);
		while(bySpace != "0")
		{
			//toupper byspace
			Actor.push_back(element(bySpace));
			Actor[a].link = theMovies[M].link;
			a++;
			bySpace = parseSpaces(actors);
			//build actors vector
			//set pointers
		}

		bySpace = parseSpaces(rating);
		Rating.push_back(element(bySpace));
		Rating[r].link = theMovies[M].link;
		r++;
		M++;
/*
		sort(Movie.begin(), Movie.end());
		sort(Director.begin(), Director.end());
		sort(Actor.begin(), Actor.end());
		sort(Rating.begin(), Rating.end());
		//build rating vector
		//set pointers

		// Iteratively read strips from the rawData
		/* For each category/strip read :
		 * 1) Search for spot in kindList for data element
		 * 2) Assign a kindList.element block for that strip
		 * 3) Link element.MoviePtr -> Movie
		 */
		// Return 0 if fail; 1 if success
		return true;
	}

	void data::Display()
	{
		//vector<element>::iterator it;
		int i=0;
		//for(it = Movie.begin(); it != Movie.end(); it++)
		for(i=0;i<Movie.size();i++)
			cout << Movie[i].Name << "   ";
		cout << endl;
		i=0;
		for(i=0;i<Rating.size();i++)
			cout << Rating[i].Name << "   ";
		cout << endl;
		i=0;
		for(i=0;i<Director.size();i++)
			cout << Director[i].Name << "   ";
		cout << endl;
		i=0;
		for(i=0;i<Actor.size();i++)
			cout << Actor[i].Name << "   ";
		cout << endl;
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
	stopWatch::~stopWatch()		// Class destructor
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
