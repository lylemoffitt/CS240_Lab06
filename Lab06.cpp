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
			comma = 0;
			space = 0;
			getline(FILE, item);
			addNew(item);
		}
		//SORT();
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
		if(rawData.at(comma) == rawData.size())
		{
			comma = 0;
			return "0";
		}
		else if(rawData.at(comma) == ' ')
			comma += 1;
		string temp, TEMP;
		int i=0, diff= rawData.size() - comma;
		while(rawData.at(comma) != ',' && i < diff)
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
		if(space == rawData.size())
		{
			space = 0;
			return "0"; //or we can say while string.at(string.length()) != comma in addnew function
		}
		else if(rawData.at(space) == ' ')
			space += 1;
		else if(rawData.at(space) == ',')
			space += 2;
		string temp, TEMP;
		int i=0, diff = rawData.size() - space;
		while(i < diff && rawData.at(space) != ' ' && rawData.at(space) != ',')
		{
			TEMP = rawData.at(space);
			temp.append(TEMP);
			space++;
			i++;
		}
		//rawData.erase(pos,i);
		return temp;
	}

	string data::parseActors(string rawData)
	{
		string temp, TEMP;
		//make a check
		if(rawData.at(comma) == ' ')
			comma += 1;
		else if(rawData.at(comma) == (rawData.size() - 1))
		{
			comma = 0;
			return "0";
		}
		int i=0, diff= rawData.size() - comma;
		while(i < diff)
		{
			TEMP = rawData.at(comma);
			temp.append(TEMP);
			comma++;
			i++;
		}
		return temp;
	}

	string data::stringToupper(string rawData)
	{
		int i=0;
		while(i < rawData.size())
		{
			rawData.at(i) = toupper(rawData.at(i));
			i++;
		}
		return rawData;
	}


	bool data::addNew(string rawData) // IF parseCommas is run outside of this, then the param can be empty
	{
		string movie, rating, director, actors, bySpace;
		int compare = 0;
		vector<element>:: iterator it;
		movie = parseCommas(rawData);
		theMovies.push_back(element(movie));

		rating = parseCommas(rawData);
		director = parseCommas(rawData);
		actors = parseActors(rawData);

		bySpace = parseSpaces(movie);
		while(bySpace != "0")
		{
			//toupper byspace
			bySpace = stringToupper(bySpace);
			compare = SORT(Movie, bySpace);
			if(compare == 0)
				Movie.push_back(element(bySpace));
			else
			{
				//***in progress***//
				it = &Movie[compare];
				Movie[compare].insert(element(bySpace));
			}
			Movie[m].Link = theMovies[M].Link;
			m++;
			bySpace = parseSpaces(movie);
			//build movie vector
			//set pointers
		}

		bySpace = parseSpaces(director);
		while(bySpace != "0")
		{
			//toupper byspace
			bySpace = stringToupper(bySpace);
			Director.push_back(element(bySpace));
			Director[d].Link = theMovies[M].Link;
			d++;
			bySpace = parseSpaces(director);
			//build director vector
			//set pointers
		}

		bySpace = parseSpaces(actors);
		while(bySpace != "0")
		{
			//toupper byspace
			bySpace = stringToupper(bySpace);
			Actor.push_back(element(bySpace));
			Actor[a].Link = theMovies[M].Link;
			a++;
			bySpace = parseSpaces(actors);
			//build actors vector
			//set pointers
		}

		bySpace = parseSpaces(rating);
		Rating.push_back(element(bySpace));
		Rating[r].Link = theMovies[M].Link;
		r++;
		M++;


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

	int data::SORT(vector<element> obj, string rawData)
	{
		sort

//		int i=0;
//		while( i < obj.size())
//		{
//			if(obj[i].Name.compare(rawData) == 0)
//				return i;
//			else if(obj[i].Name.compare(rawData) == -1)
//				i++;
//			else if(obj[i].Name.compare(rawData) == 1)
//				return i-1;
//			else
//				return 0;
//		}
		return 0;
	}

	void data::Display()
	{
		//vector<element>::iterator it;
		int i=0;
		//for(it = Movie.begin(); it != Movie.end(); it++)
		for(i=0;i<Movie.size();i++)
			cout << Movie[i].Name << endl;
		cout << endl;
		i=0;
		for(i=0;i<Rating.size();i++)
			cout << Rating[i].Name << endl;
		cout << endl;
		i=0;
		for(i=0;i<Director.size();i++)
			cout << Director[i].Name << endl;
		cout << endl;
		i=0;
		for(i=0;i<Actor.size();i++)
			cout << Actor[i].Name << endl;
		cout << endl;
	}

	int data::binarySearch(kindList list, string search_term)
	{
		int i;
		int bottom = 0, top = 0, middle = 0, found = 0;
		top = list.size();
		search_term = stringToupper(search_term);
		while(bottom < top && found == 0)
		{
			middle = (top + bottom)/2;
			if( search_term == list[middle].Name)
			{
				found = 1;
				i = middle;
			}
			else if(list[middle].Name > search_term)
				top = middle-1;
			else
				bottom = middle + 1;
		}

		if(found == 1)
			return i;
		else
			return -1;
		// This could be potentially be replaced by std::binary_search from the algorithm library
		// .. though, i don't know how easily we can adapt that to our needs
		// Use std::string.compare() to determine break direction.
		// Use kindList.size() for START and END markers
		// Return an indexPtr to the first matching element or nullptr if not found
		return 0;
	}
	data::kindList data::getKind(category group)
	{
		switch( group )
		{
			case T:
				return Movie;
			case R:
				return Rating;
			case D:
				return Director;
			case S:
				return Actor;
			default:
				return theMovies;
		}
	}

	bool data::getMatch(category group, string sub_string)
	{
		vector<element::MoviePtr> vecTemp;
		element Temp;
		int found = binarySearch(getKind(group),sub_string);
		if(found == -1) { return false;}
		do{
			Temp = getKind(group).at(found);
			if (Temp.Name == sub_string){
				for( int i=0; vecTemp[i] >= vecTemp.end(); ++i )
				{
					if(vecTemp[i] == Temp){	break;	}

				}

			}
		} while ( )


		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
	}

	void data::printMatch(element::MoviePtr titlePtr)
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




		//sorting Movie
		int k = Movie.size();
		string *first = &Movie[0].Name;
		string *last = &Movie[Movie.size()-1].Name;
		sort(first, last);
		//sorting director
		k = Director.size();
		first = &Director[0].Name;
		last = &Director[Director.size()-1].Name;
		sort(first, last);
		//sorting actor
		k = Actor.size();
		first = &Actor[0].Name;
		last = &Actor[Actor.size()-1].Name;
		sort(first, last);
		//sorting rating
		k = Rating.size();
		first = &Rating[0].Name;
		last = &Rating[Rating.size()-1].Name;
		sort(first, last);

