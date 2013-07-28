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
	Movie.clear();
	delete &Movie;
	Director.clear();
	delete &Director;
	Rating.clear();
	delete &Rating;
	Actor.clear();
	delete &Actor;
	//This was shooting back errors, it was giving me that memory map thing
	//I had last night. Jess said she thinks we don't need to put anything
	//in the destructor
	//Tania's had this commented out.
	//	{
	//		//	Movie.clear();
	//		delete Movie;
	//		//	Director.clear();
	//		delete Director;
	//		//	Rating.clear();
	//		delete Rating;
	//		//	Actor.clear();
	//		delete Actor;
	//		delete theMovies;
	//	}
}

//takes in the file and reads the first line and returns the string -Tania
string data::readFile(istream& FILE)
{
	stopWatch timer;
	string item;
	timer.timeGo();
	while(!FILE.eof())
	{
		comma = 0;
		space = 0;
		getline(FILE, item);
		if(!FILE.eof())
			addNew(item);
	}
	timer.timeStop();
	cout << timer.duration() << "ms to import" << endl;
	Display();
	sortElem();
	timer.timeStop();
	cout << timer.duration() << "ms to import & sort" << endl;
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
	//if(rawData.at(comma) == rawData.size())
	//^ that doesn't make sense...did I have that before?
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
		++comma;
	}
	++comma;
	return temp;
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
	while( (i<diff) &&
		   (rawData.at(space) != ' ') &&
		   (rawData.at(space) != ',') )
	{
		TEMP = rawData.at(space);
		temp.append(TEMP);
		++space;
		++i;
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
	//else if(rawData.at(comma) == (rawData.size() - 1))
	//^ same thing as before, doesn't really make sense
	else if(comma == rawData.size())
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
	while(i < rawData.length())
	{
		rawData.at(i) = toupper(rawData.at(i));
		++i;
	}
	return rawData;
}


bool data::addNew(string rawData) // IF parseCommas is run outside of this, then the param can be empty
{
	string movie, rating, director, actors, bySpace;
	//vector<element>:: iterator it;
	movie = parseCommas(rawData);
	theMovies.push_back(element(movie));
	((element)theMovies[M]).link = &theMovies[M];
	//I get an error saying "expression must a modifiable lvalue"
	rating = parseCommas(rawData);
	director = parseCommas(rawData);
	actors = parseActors(rawData);

	bySpace = parseSpaces(movie);
	while(bySpace != "0")
	{
		//toupper byspace
		bySpace = stringToupper(bySpace);
		Movie.push_back(element(bySpace));
		((element)Movie[m]).link = &theMovies[M];
		cout << ((element)Movie[m]).link->Name<< endl;
		++m;
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
		((element)Director[d]).link = &theMovies[M];
		cout << ((element)Director[d]).link->Name<< endl;
		++d;
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
		((element)Actor[a]).link = &theMovies[M];
		cout << ((element)Actor[a]).link->Name<< endl;
		++a;
		bySpace = parseSpaces(actors);
		//build actors vector
		//set pointers
	}

	bySpace = parseSpaces(rating);
	Rating.push_back(element(bySpace));
	((element)Rating[r]).link = &theMovies[M];
	cout << ((element)Rating[r]).link->Name<< endl;
	++r;	++M;
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
/* Replaced with data::operator<
bool data::compareElem(element ONE, element TWO)
{
	if(ONE.Name.empty() || TWO.Name.empty())
		return false;
	else if(ONE.Name.compare(TWO.Name) == 0)
		return false;
	else if(ONE.Name.compare(TWO.Name) < 0)
		return false;
	else if(ONE.Name.compare(TWO.Name) > 0)
		return true;
	else
		return false; //Fail on exception
}
*/
void data::sortElem()
{
	sort(Movie.begin(), Movie.end());//sorting Movie
	sort(Director.begin(), Director.end());//sorting director
	sort(Rating.begin(), Rating.end());//sorting rating
	sort(Actor.begin(), Actor.end());//sorting actor
}

void data::Display()
{
	//vector<element>::iterator it;
	int i=0;
	//for(it = Movie.begin(); it != Movie.end(); it++)
	cout <<"theMovies"<<endl;
	for(i=0; i<theMovies.size(); ++i)
		cout << ((element)theMovies[i]).Name << endl;
	cout << endl << "movie" << endl;
	for(i=0;i<Movie.size();++i)
	{
		cout << i << endl;
		if( ((element)Movie[i]).link == nullptr )
		{
			cout <<"i: " << i << "   empty"<<endl;
		}
		else
			cout << ((element)Movie[i]).link->Name << endl;
	}
	cout << endl<<"rating"<<endl;
	for(i=0;i<Rating.size();++i)
		cout << ((element)Rating[i]).link->Name << endl;
	cout << endl<<"director" << endl;
	for(i=0;i<Director.size();i++)
		cout << ((element)Director[i]).link->Name << endl;
	cout << endl<< "actor"<< endl;
	for(i=0;i<Actor.size();i++)
		cout << ((element)Actor[i]).link->Name << endl;
	cout << endl;
}

int data::binarySearch(kindList list, string search_term)
{
	int compVal;
	int bottom = 0, top = 0, middle = 0;
	top = list.size();
	search_term = stringToupper(search_term);
	while( bottom <= top )
	{
		middle = (top + bottom)/2;
		compVal = search_term.compare( ((element)list[middle]).Name );
		if( compVal == 0)
		{	return middle; //Much faster than setting found
		}else if( compVal > 0 )
		{	top = middle - 1;
		}else
		{	bottom = middle + 1;
		}
	}
	return -1;
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
	vector<element::MoviePtr> vecTemp;//Temp vector to hold reverences for all elements that match
	element::MoviePtr Temp;//Temp Ptr to the matching element
	int found=0;
	//Iniiialize
	string  keyword,lastword;
	char cat;
	int i=0,k_num=0;
	double rat1=0.0,rat2=10.0,ratComp;

	//Parse Category
	i = lineStr.find_first_of("TRDS",0);
	//for lab make another int j = lineStr.find_first_of("TRDS", 0);
	cat = lineStr.at(i);
	//char cat2 = lineStr.at(j);
	lineStr.erase(0,i);
	//int star = lineStr.find("*");
	//lineStr.erase(star, j);
	//check to see if any double spaces lineStr.find("  ", 0);
	//erase if any. size_t findDouble = lineStr.find("  ", 0);
	//if findDouble == npos)
	//else lineStr.erase(findDouble);
	//should we account for the possibility that the user will accidentally type in two spaces?
	//such as T Harry  Potter instead of
	//        T Harry Potter
	
	//Parse remaining keywords
	//can't compare an int with an iterator
	//try using lineStr.size() if you want the index one past the last element
	while(lineStr.find_first_of(" ",0) < lineStr.end() )
	{
		// Use binarysearch to find first match
		// Use linear search up, and then down to find all possible adjacent matches
		i = lineStr.find_first_of(" \n\0",0);
		keyword = lineStr.substr(0,i);
		//or we don't make a cat2
		//and we check to see if it is one of the key letters
		//if(keyword == 'R' || keyword == 'T' || keyword == 'D' || keyword == 'S')
		//{cat2 = keyword
		//lineStr.erase(0,i);
		//i = lineStr.find_first_or(" \n\0",0);
		//keyword = lineStr.subset(0,i);
		// }
		lineStr.erase(0,i);
		if(cat == 'R'){
			char* spc;     // alias of size_t

			rat1= strtod(lineStr.data(),&spc);
			if(spc != '\0'){
				rat2 = strtod(spc,NULL);
			} else {
				rat2=10.0;
			}
			lineStr.clear();
		}
		//k_num=0 --> Populate initial match-list
		//k_num>0 --> Remove non-matches
		found = binarySearch(getKind(cat),keyword);//found matching index #
		if(found == -1) { return false;}// -1 = "No match found"
		Temp = &(getKind(cat).at(found));//Copy elemtent reference to temp
		for( int l=0, k[2]={-1,1}; l<2 ; ++l )//Initialize mode counter, and mode list
		{
			int j=k[l];
			bool exit=true;
			while(exit)
			{
				ratComp = strtod(Temp->Name.data(),NULL);
				if ( (rat1<=ratComp && rat2>=ratComp)||
					 (Temp->Name.compare(lineStr)==0 )	 ){  //Check for match
				} else{	exit = false;	break; }
				for( int i=0; i <= vecTemp.size(); ++i )//If found, check for dublicate in vecTemp
				{
					if( Temp == vecTemp[i] ){
						if(k_num==0){ break; //If duplicate, skip and get next (FAST Initialize)
						} else{ continue; }//If it matched go to the next and check it.
					} else if( (i==vecTemp.size()) && //If end of list is reached without match
							   (k_num==0) ){//AND this is the first keyword
						vecTemp.push_back(Temp->link);//Then append reference to vector
					} else {//IF the pointer does not match, and it is not the first word
						vecTemp.erase(vecTemp.begin() +i);//Remove that
					}
				}
				j+=k[l];
				Temp = &(getKind(cat).at(found+j)) ;//Get next element
			}
		}
	}
	if (vecTemp.empty()){	return false;	} //False for no matches or conflicting keywords
	for(int i=0; i<vecTemp.size(); ++i)
	{
		Temp = vecTemp[i];
		cout << Temp->link << " ??is the same as?? ";
		cout << ((indexPtr)vecTemp[i])->link->Name << endl;
	}
	return true; // DONE!!!!


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


