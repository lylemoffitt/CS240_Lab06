//functions
#include "Lab06.h"
using namespace std;

bool operator< (const data::element& ONE, const data::element& TWO)
{
	if(ONE.Name.empty() || TWO.Name.empty())
		return false;
	else if(ONE.Name.compare(TWO.Name) == 0)
		return false;
	else if(ONE.Name.compare(TWO.Name) < 0)
		return true;
	else if(ONE.Name.compare(TWO.Name) > 0)
		return false;
}


//class data
// Class constructor
	data::data()
	{
		comma = 0;
		space = 0;
		m=0;
		d=0;
		r=0;
		a=0;
		M=0;

	}


	// Class destructor
	data::~data()
	{/*
	//	Movie.clear();
		delete Movie;
	//	Director.clear();
		delete Director;
	//	Rating.clear();
		delete Rating;
	//	Actor.clear();
		delete Actor; 
		delete theMovies;*/
	}

	string data::readFile(istream& FILE)
	{
		string item;
		//getline(FILE, item);
		while(!FILE.eof())
		{
			comma = 0;
			space = 0;
			getline(FILE, item);
			if(!FILE.eof())
				addNew(item);
		}
		Display();
		sortElem();
		// Takes in the initialization file as input.
		// Returns the length of the raw data string from the file, or zero on failure
		return item;
	}

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
		// Read raw data string up to first comma
		// Return string with leading/trailing whitespace stripped
		// Repeat until string.end()
	}

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
		//theMovies[M].link = &(theMovies[M]);

		rating = parseCommas(rawData);
		director = parseCommas(rawData);
		actors = parseActors(rawData);

		bySpace = parseSpaces(movie);
		while(bySpace != "0")
		{
			bySpace = stringToupper(bySpace);
			Movie.push_back(element(bySpace));
			Movie[m].link = &theMovies[M];
			//cout << Movie[m].link->Name << endl;
			m++;
			bySpace = parseSpaces(movie);
		}

		bySpace = parseSpaces(director);
		while(bySpace != "0")
		{
			//toupper byspace
			bySpace = stringToupper(bySpace);
			Director.push_back(element(bySpace));
			Director[d].link = &theMovies[M];
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
			Actor[a].link = &theMovies[M];
			a++;
			bySpace = parseSpaces(actors);
			//build actors vector
			//set pointers
		}

		bySpace = parseSpaces(rating);
		Rating.push_back(element(bySpace));
		Rating[r].link = &theMovies[M];
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

	void data::sortElem()
	{
		//sorting Movie
		//int k = Movie.size();
		sort(Movie.begin(), Movie.end());
		sort(Director.begin(), Director.end());
		sort(Rating.begin(), Rating.end());
		sort(Actor.begin(), Actor.end());
		//sorting director
	}

	void data::Display()
	{
		//vector<element>::iterator it;
		int i=0;
		//for(it = Movie.begin(); it != Movie.end(); it++)
		cout <<"theMovies"<<endl;
		for(i=0; i<theMovies.size(); i++)
			cout << theMovies[i].Name << endl;
		cout << endl << "movie" << endl;
		for(i=0;i<Movie.size();i++)
		{
			cout << i << endl;
			if(Movie[i].link == nullptr)
			{
				cout <<"i: " << i << "   empty"<<endl;
			}
			else
				cout << Movie[i].link->Name << endl;
		}
		cout << endl<<"rating"<<endl;
		i=0;
		for(i=0;i<Rating.size();i++)
			cout << Rating[i].link->Name << endl;
		cout << endl<<"director" << endl;
		i=0;
		for(i=0;i<Director.size();i++)
			cout << Director[i].link->Name << endl;
		cout << endl<< "actor"<< endl;
		i=0;
		for(i=0;i<Actor.size();i++)
			cout << Actor[i].link->Name << endl;
		cout << endl;
	}

	int data::binarySearch(kindList list, string search_term)
	{
		int i;
		int bottom = 0, top = 0, middle = 0, found = 0;
		top = list.size();
		//search_term = stringToupper(search_term);
		while(bottom <= top && found == 0)
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

	data::kindList data::getKind(char group)
	{
		switch( group )
		{
			case 'T':
				return Movie;
			case 'R':
				return Rating;
			case 'D':
				return Director;
			case 'S':
				return Actor;
			default:
				return theMovies;
		}
	}

	void data::getKind(char group, int found, string keyword)
	{
		int i=0;
		switch( group )
		{
			case 'T':
				for(i=found;i<Movie.size(); i++)
				{
					if(Movie[i].Name == keyword)
						cout << Movie[i].link->Name << endl;
					else
						break;
				}
				for(i=found-1;i>=0; i--)
				{
					if(Movie[i].Name == keyword)
						cout << Movie[i].link->Name << endl;
					else
						break;
				}
				break;
			case 'D':
				for(i=found;i<Director.size();i++)
				{
					if(Director[i].Name == keyword)
						cout << Director[i].link->Name << endl;
					else
						break;
				}
				for(i=found-1;i>=0;i--)
				{
					if(Director[i].Name == keyword)
						cout << Director[i].link->Name << endl;
					else
						break;
				}
				break;
			case 'S':
				for(i=found;i<Director.size();i++)
				{
					if(Actor[i].Name == keyword)
						cout << Actor[i].link->Name << endl;
					else
						break;
				}
				for(i=found-1;i>=0;i--)
				{
					if(Actor[i].Name == keyword)
						cout << Actor[i].link->Name << endl;
					else
						break;
				}
				break;
			default:
				cout << "Error, Stopping compilation.\n";
				break;
			}
	}

	bool data::getMatch()
	{
		string search, keyword, endBound;
		char cat;
		kindList temp;
		int found = 0, i=0;
		cout << "Type Exit to stop searching \nSearch: ";
		getline(cin, search);
		search = stringToupper(search);
		do{
			cat = search.at(0);
			if(search.at(1) == ' ')
				search.erase(0,2);
			else
				search.erase(0,1);
			space = 0;
			keyword = parseSpaces(search);
			while(keyword != "0")
			{
				found = binarySearch(getKind(cat), keyword);
				if(found == -1)
					return false;
				if(cat == 'R')
				{
					findRating(keyword, search, found);
				}
				else
					getKind(cat, found, keyword);
				keyword = parseSpaces(search);
			}
			cout << "Type Exit to stop searching \nSearch: ";
			getline(cin, search);
			search = stringToupper(search);
		}while(search != "EXIT");

		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
		return 0;
	}
	void data::findRating(string firstBound, string search, int found)
	{
		string endBound = parseSpaces(search);
		if(endBound == "0")
			endBound = "10.0";
		int i = 0;
		for(i=found; i>=0;i--)
		{
			if(Rating[i].Name.compare(firstBound) == 0)
				cout << Rating[i].link->Name << endl;
			else
				break;
		}
		i = found+1;
		if(i >= Rating.size())
			return;
		else
		{
			do{
				cout << Rating[i].link->Name << endl;
				i++;
			} while(Rating[i].Name.compare(endBound) <= 0);
		}/*
		for(;i<Rating.size();i++)
		{
			if(Rating[i].Name == endBound)
				cout << Rating[i].link->Name << endl;
			else
				break;
		}*/
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
//		startTime = chrono::system_clock::now().time_since_epoch()/chrono::milliseconds(1);
	}
	void stopWatch::timeStop()		// Start the clock
	{
//		stopTime = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	}
	long stopWatch::duration()	// Return the total duration
	{
		// This probably needs to be formatted..
		return stopTime-startTime;
	}


