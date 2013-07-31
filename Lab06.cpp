//functions

#include "Lab06.h"
#ifdef LINUX
using namespace boost;
#endif
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
	else
		return false;
}

//class data
// Class constructor
	data::data()//:theMovies(vector<element>(10000))
	{
		comma = 0;
		space = 0;
		m=0;
		d=0;
		r=0;
		a=0;
		M=0;
		theMovies.reserve(20);
	}
	

	// Class destructor
	data::~data(){}

	string data::readFile(ifstream& FILE)
	{
		string item,tmpStr;
		stopWatch timer;
		timer.timeGo();
		getline(FILE, tmpStr);
		do
		{
			item = tmpStr.c_str();
			comma = 0;
			space = 0;
			addNew(item);
			getline(FILE, tmpStr);
		}while(FILE.good());
		timer.timeStop();
		cout << timer.duration() << "ms to import" << endl;
		Display();
		sortElem();
		timer.timeStop();
		cout << timer.duration() << "ms to import & sort" << endl;
		//fetch();
		getMatch();
		// Takes in the initialization file as input.
		// Returns the length of the raw data string from the file, or zero on failure
		return "0";
	}

	string data::parseCommas(string rawData)
	{
		//if(rawData.at(comma) == rawData.size())
		if(comma == rawData.size())
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

//Takes `input` string and returns first substring deliminated by `delimz`
//To get the first non-space & non-comma substring -> delimz = " ,"
string data::trimDelim(string input, string delimz)
{
	int start = input.find_first_not_of(delimz.data(),0);
	if( start <0 ){	return "0";	} //Return "0" if no substring exists
	int stop = input.find_first_of(delimz.data(),0);
	if( stop <=0 ){	stop = input.length();	} //Catch EOL exception not specified in `delimz`
	string output = input.substr(start,stop);\

	if ( delimz.find_first_of("-",delimz.length()) ){	input.erase(start,stop);	}
	if ( delimz.find_first_of("c",delimz.length()) ){	++comma;	}
	if ( delimz.find_first_of("s",delimz.length()) ){	++space;	}

	return output;//Return the specified substring as excluded by `delimz`
	//Also delete the substring from input if `delimz` has "\0-" terminus
}

string data::parseActors(string rawData)
	{
		string temp, TEMP;
		//make a check
		if(rawData.at(comma) == ' ')
			comma += 1;
		//else if(rawData.at(comma) == (rawData.size() - 1))
		else if(comma == rawData.size() - 1)
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
	while(i < (int)rawData.length())
	{
		int i=0;
		while(i < rawData.size())
		{
			rawData.at(i) = toupper(rawData.at(i));

			i++;   
		}
		return rawData;
	}

}
	bool data::addNew(string rawData) // IF parseCommas is run outside of this, then the param can be empty
	{
		string movie, rating, director, actors, bySpace;
		int compare = 0;
		//vector<element>:: iterator it;
		movie = parseCommas(rawData);
		theMovies.push_back(element(movie));
		theMovies[M].link = nullptr;
		
		rating = parseCommas(rawData);
		director = parseCommas(rawData);
		actors = parseActors(rawData);

		bySpace = parseSpaces(movie);
		while(bySpace != "0")
		{
			//toupper byspace
			bySpace = stringToupper(bySpace);
			Movie.push_back(element(bySpace));
			Movie[m].link = &theMovies[M];
			//cout << Movie[m].link->Name<< endl; ///////////////////////////////////////////
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
			Director[d].link = &theMovies[M];
			//////***try using &theMovies[M].Name***/////////////
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
		sort(Movie.begin(), Movie.end());
		sort(Director.begin(), Director.end());
		sort(Rating.begin(), Rating.end());
		sort(Actor.begin(), Actor.end());
	}

	
	void data::Display()
	{ //booga booga booga
		int i=0;
		cout << "theMovies\n";
		for(i=0;i<theMovies.size();i++)
			cout << theMovies[i].Name << endl;
		cout << endl << "Movie\n";
		for(i=0;i<Movie.size();i++)
			cout << Movie[i].link->Name << endl;
		cout << endl << "Rating\n";
		for(i=0;i<Rating.size();i++)
			cout << Rating[i].link->Name << endl;
		cout << endl << "Director\n";
		for(i=0;i<Director.size();i++)
			cout << Director[i].link->Name << endl;
		cout << endl << "Actor\n";
		for(i=0;i<Actor.size();i++)
			cout << Actor[i].link->Name << endl;
		cout << endl;
	}
	//github has something different
	int data::binarySearch(kindList list, string search_term)
	{
		return binarySearch(list,search_term,search_term);
	}

int data::binarySearch(kindList list, string search_term, string last_term)
	{
		int i=0;
		int bottom = 0, top = 0, middle = 0, found = 0, c[4]={0};
		top = list.size();
		search_term = stringToupper(search_term);
		last_term = stringToupper(last_term);
		while(bottom <= top && found == 0 )
		{
			middle = (top + bottom)/2;
			if( ( search_term <= list[middle].Name) &&
				( last_term >= list[middle].Name) )
			{
				found = 1;
				i = middle;
				return i;
			}
			else if(list[middle].Name < search_term)
				bottom = middle-1;
			else if(list[middle].Name > last_term)
				top = middle+1;
			c[3]=c[2];
			c[2]=c[1];
			c[1]=c[0];
			c[0]=middle;
			
			if (c[0]==c[1] &&c[1]==c[2] && c[2]==c[3])
				break;
		}

		if(found == 1)
			return i;
		else
			return -i;
		// This could be potentially be replaced by std::binary_search from the algorithm library
		// .. though, i don't know how easily we can adapt that to our needs
		// Use std::string.compare() to determine break direction.
		// Use kindList.size() for START and END markers
		// Return an indexPtr to the first matching element or nullptr if not found
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
				cout << "Not an option, stopping Program\n";
				vector<element> Null;
				return Null;
		}
	}

	
//////////////////////////////////////////NEW GETMATCH FUNCTION/////////////////////////////////////////////////
void data::fetch()
{
	stopWatch timer;
	string lineStr;
	do{//Read IN
		cout << "Type Exit to stop lineString \nSearch: ";
		getline(cin, lineStr);
		lineStr = stringToupper(lineStr);
		timer.timeGo();//Start clock
		if (getMatches(lineStr)){
			cout << "\nNOT found!\n" << endl;
		}
		timer.timeStop();
		cout << timer.duration() << "ms to search" << endl;

	} while (lineStr != "EXIT");//if -then-> return;
}


bool data::getMatches(/*category group,*/ string lineStr)
{
	if( lineStr.length() <=0 ){	return false;	}
	vector<element::MoviePtr> vecTemp;//Temp vector to hold reverences for all elements that match
	element::MoviePtr Temp;//Temp Ptr to the matching element
	int found=0;
	//Iniiialize
	char cat='\0',cat2='\0';
	string  keyword, secStr;
	int i, k_num=0;
	double rat1=0.0, rat2=10.0, ratComp;

	//Parse Category #1
	i = lineStr.find_first_of("TRDS",0);
	cat = lineStr.at(i);
	lineStr.erase(0,(2+i));

	i = lineStr.find_first_of("*&",0);
	if (i > 0)
	{
		lineStr.erase(i,0); //Remove the duplex character(* or &)
		secStr = lineStr.substr(i,-1); //Copy second search into new string
		lineStr.erase(i,-1);//Remove second string from first
		i = secStr.find_first_of("TRDS",0);
		cat2 = secStr.at(i);
		secStr.erase(0,i);
	}
	//int star = lineStr.find("*");
	//lineStr.erase(star, j);
	//check to see if any double spaces lineStr.find("  ", 0);
	//erase if any. size_t findDouble = lineStr.find("  ", 0);
	//if (findDouble == npos)
	//else lineStr.erase(findDouble);
	//should we account for the possibility that the user will accidentally type in two spaces?
	//such as T Harry  Potter instead of
	//        T Harry Potter

	//Parse remaining keywords
	//can't compare an int with an iterator
	//try using lineStr.size() if you want the index one past the last element
	while( true )
	{//Loops once or twice depending on the condition of cat2(second category specifier)
		while( lineStr.length() > 0 )
		{
			// Use binarysearch to find first match
			// Use linear search up, and then down to find all possible adjacent matches
			i = lineStr.find_first_of(" \n\0",0);
			keyword = lineStr.substr(0,i);
			if( keyword.length() <=0 ){	break;	}
			lineStr.erase(0,i);
			if( cat == 'R' )
			{	char* spc;     // alias of size_t
				//Convert rating substring(s) to double
			rat1= (double)strtod(lineStr.c_str(),&spc);
				if(spc != '\0')
				{	rat2 = (double)strtod(spc,NULL);
				} else
				{	rat2=10.0;
				}
				lineStr.clear();
			}
			//k_num=0 --> Populate initial match-list
			//k_num>0 --> Remove non-matches
			found = binarySearch(getKind(cat),keyword);//found matching index #
			if( found == -1 ){	return false;	}// -1 = "No match found"
			Temp = &(getKind(cat).at(found));//Copy elemtent reference to temp
			int k[2]={-1,1};
			for( int l=0; l<2 ; ++l )//Initialize mode counter, and mode list
			{
				int j=k[l];
				while(true)
				{
					ratComp = (double)strtod(Temp->Name.c_str(),nullptr);
					if ( (rat1<=ratComp && rat2>=ratComp) ||
						 (Temp->Name.compare(keyword)==0 )	 )
					{ //Empty statement means "continue on", since alternate is break
					} else
					{	break;	}
					for( int i=0; i <= (int)vecTemp.size(); ++i )//If found, check for dublicate in vecTemp
					{
						if( Temp == vecTemp[i] )
						{	if(k_num==0)
							{	break; //If duplicate, skip and get next (FAST Initialize)
							} else
							{	continue; //If it matched go to the next and check it.
							}
						} else if( (i==(int)vecTemp.size()) && //If end of list is reached without match
								   (k_num==0) )//AND this is the first keyword
						{	vecTemp.push_back(Temp->link);//Then append reference to vector
						} else //IF the pointer does not match, and it is not the first word
						{	vecTemp.erase(vecTemp.begin() +i);//Remove that
						}
					}
					j+=k[l];
					Temp = &(getKind(cat).at(found+j)) ;//Get next element
				}
			}
		}
		if (cat2 != '\0')
		{	cat=cat2; //Transfer search params
			lineStr = secStr;
			cat2 = '\0'; //Set break contition
			continue; //Repeat search loop with new params
		}else
		{	break; //Exit loop
		}

	}
	if (vecTemp.empty()){	return false;	} //False for no matches or conflicting keywords
	for(int i=0; i<(int)vecTemp.size(); ++i)
	{
		Temp = vecTemp[i];
		cout << Temp->link << " ??is the same as?? ";
		cout << ((indexPtr)vecTemp[i])->link->Name << endl;
	}
	return true; // DONE!!!!


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void data::getKind(char group, int found, string keyword)
	{
		int i=0;
		switch( group )
		{
			case 'T':
				for(i=found; i<Movie.size(); i++)
				{
					if(Movie[i].Name == keyword)
					{
						cout << Movie[i].link->Name << endl;
						vecTemp.push_back(Movie[i].link->Name);
					}
					else
						break;
				}
				for(i=found-1; i>=0; i--)
				{
					if(Movie[i].Name == keyword)
					{
						cout << Movie[i].link->Name << endl;
						vecTemp.push_back(Movie[i].link->Name);
					}
					else 
						break;
				}
				break;
			case 'D':
				for(i=found; i<Director.size();i++)
				{
					if(Director[i].Name == keyword)
					{
						cout << Director[i].link->Name << endl;
						vecTemp.push_back(Director[i].link->Name);
					}
					else
						break;
				}
				for(i=found-1;i>=0;i--)
				{
					if(Director[i].Name == keyword)
					{
						cout << Director[i].link->Name << endl;
						vecTemp.push_back(Director[i].link->Name);
					}
					else
						break;
				}
				break;
			case 'S':
				for(i = found; i<Actor.size();i++)
				{
					if(Actor[i].Name == keyword)
					{
						cout << Actor[i].link->Name << endl;
						vecTemp.push_back(Actor[i].link->Name);
					}
					else
						break;
				}
				for(i = found-1;i>=0;i--)
				{
					if(Actor[i].Name == keyword)
					{
						cout << Actor[i].link->Name << endl;
						vecTemp.push_back(Actor[i].link->Name);
					}
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
		string search, keyword, endBound, secondSearch, firstBound;
		char cat1, cat2;
		int firstX, secondX, star, space2;
		kindList temp;
		int found = 0, i=0;
		cout << "Type Exit to stop searching \nSearch: ";
		getline(cin, search);
		search = stringToupper(search);
		while(search != "EXIT")
		{
			firstX = search.find_first_of("TRDS", 0);
			cat1 = search.at(firstX);
			if(search.at(firstX+1) == ' ')
				search.erase(0,firstX+2);
			else 
				search.erase(0,firstX+1);
			space = 0;
			keyword = parseSpaces(search);
			while(keyword.compare("0") != 0)
			{
				found = binarySearch(getKind(cat1), keyword);
				if(found < 0)
				{
					cout << "No matches found\n";
					return false;
				}
				if(cat1 == 'R')
				{
					endBound = parseSpaces(search);
					firstBound = keyword;
					keyword = endBound;
					if(endBound == "0" || endBound == "*")
						endBound = "9.99";
					found = binarySearch(getKind(cat1), firstBound, endBound);
					findRating(firstBound, endBound, found);
				}
				else
					getKind(cat1, found, keyword);
				if(keyword == "*")
				{
					star = search.find_first_of("*", 0);
					star = search.find_first_not_of(" ", star+1);
					secondSearch = search.substr(star);
					keyword = getStarMatch(secondSearch);
				}
				if(keyword == "0")
					break;
				keyword = parseSpaces(search);
				if(keyword == "*")
				{
					star = search.find_first_of("*", 0);
					star = search.find_first_not_of(" ", star+1);
					secondSearch = search.substr(star);
					keyword = getStarMatch(secondSearch);
				}
			}
			cout << "Type Exit to stop searching \nSearch: ";
			getline(cin, search);
			search = stringToupper(search);
			found = 0, i=0;
		}

		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
		return 0;
	}

	string data::getStarMatch(string search)
	{
		string keyword, endBound, secondSearch, firstBound;
		char cat2;
		int firstX, star;
		int found = 0, i=0;
		firstX = search.find_first_of("TRDS", 0);
		cat2 = search.at(firstX);
		if(search.at(firstX+1) == ' ')
			search.erase(0,firstX+2);
		else 
			search.erase(0,firstX+1);
		space = 0;
		keyword = parseSpaces(search);
		while(keyword.compare("0") != 0)
		{
			found = binarySearch(getKind(cat2), keyword);
			if(found < 0)
			{
				cout << "No matches found\n";
				return "";
			}
			if(cat2 == 'R')
			{
				endBound = parseSpaces(search);
				firstBound = keyword;
				keyword = endBound;
				if(endBound == "0")
					endBound = "9.99";
				found = binarySearch(getKind(cat2), keyword, endBound);
				findRating(keyword, endBound, found);
			}
			else
				getKind(cat2, found, keyword);
			if(keyword == "0")
				break;
			keyword = parseSpaces(search);
		}
		
		// Use binarySearch to find first match
		// Use linear search up, and then down the block to find all possible adjacent matches
		// printMatch() for each match found
		return keyword;
	}


	void data::findRating(string firstBound, string endBound, int found)
	{
		//string endBound = parseSpaces(search);
		if(endBound == "9.99")
			endBound = "10.0";
			//end = 10.0;
		int i = 0;
		if(endBound == "10.0")
		{
			for(i=found; i>=0;i--)
			{
				if(Rating[i].Name.compare(firstBound) >= 0)
				{
					cout << Rating[i].link->Name << endl;
					vecTemp.push_back(Rating[i].link->Name);
				}
				else
					break;
			}
			i = found+1;
			if(i >= Rating.size())
				return;
			for(;i<Rating.size();i++)
			{
				cout << Rating[i].link->Name << endl;
				vecTemp.push_back(Rating[i].link->Name);
			}
		}
		else
		{
			for(i=found; i>=0;i--)
			{
				if(Rating[i].Name.compare(firstBound) >= 0)
				{
					cout << Rating[i].link->Name << endl;
					vecTemp.push_back(Rating[i].link->Name);
				}
				else
					break;
			}
			i = found+1;
			if(i >= Rating.size())
				return;
			else
			{
				while(i<Rating.size())
				{
					if(Rating[i].Name.compare(endBound) <= 0)
					{
						cout << Rating[i].link->Name << endl;
						vecTemp.push_back(Rating[i].link->Name);
						i++;
					}
					else 
						break;
				} 
			}
		}

		
	}


//class stopWatch // Time object

stopWatch::stopWatch()			// Class Constructor
{
	startTime = 0;
	stopTime = 0;
}
stopWatch::~stopWatch()		// Class destructor
{
	//	delete &startTime;
	//	delete &stopTime;
	// ^Un-necessary^
	//"Memory already freed"
}

void stopWatch::timeGo()		// Start the clock
{
	startTime = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
}
void stopWatch::timeStop()		// Start the clock
{
	stopTime = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
}
long stopWatch::duration()	// Return the total duration
{
	// This probably needs to be formatted..
	return stopTime-startTime;
}


