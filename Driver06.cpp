#include "Lab06.h"
using namespace std;

int main()
{
	string search;
	data Hello;
	ifstream file;
	file.open("imdbTest.txt", ifstream::in);
	
	Hello.readFile(file);
	Hello.fetch();

	

	//Hello.getMatch();
	//Hello.Display();

	
	/*
	string str1 = "ABCD", str2 = "EFGH";
	cout << "str1: " << str1 << endl << "str2: " << str2 << endl;
	cout << "str1.compare(str2): " << str1.compare(str2) << endl;
	cout << "str2.compare(str1): " << str2.compare(str1) << endl;

	/*
		string item, line1;
		ifstream infile("imdbTest.txt");
		getline(infile, item, ',');
		//one problem it reads in the space
		getline(infile, line1, ',');
		line1.erase(0,1); //we'll have to ask if there will always be a space after each comma
		
		int* hi;
		hi = nullptr;

		cout << item << endl << line1 << endl;

		string* strArray;
		string str = "This is the day", temp;

		int i=0;
		/*
		while(i<str.length())
		{
			//grrr
		}

		*/
	return 0;
}


//Will there always be a space after each comma?
//