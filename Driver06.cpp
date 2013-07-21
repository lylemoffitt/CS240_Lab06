#include "Lab06.h"

using namespace std;

int main()
{
		string item, line1;
		ifstream infile("imdbTest.txt");
		getline(infile, item, ',');
		//one problem it reads in the space
		getline(infile, line1, ',');
		line1.erase(0,1); //we'll have to ask if there will always be a space after each comma

		cout << item << endl << line1 << endl;
	return 0;
}


//Will there always be a space after each comma?
//