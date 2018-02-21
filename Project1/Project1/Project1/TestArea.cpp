

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


int TestArea()
{
	string inStr = "Screen door slams. Mary\'s  \n dress \n waves. Like a     vision she dances \n across the porch as the \n radio     plays.";
	char inStr2[118] = "Screen door slams. Mary\'s  \n dress \n waves. Like a     vision she dances \n across the porch as the \n radio     plays.";
	std::vector<string> inStr3 = { "Screen door slams. Mary\'s  \n dress \n waves. Like a     vision she dances \n across the porch as the \n radio     plays." };
	string outStr;
	int num = 5;
	int lineLength = 60;



	//cout << inputString<<endl;
	//cout << inputString.size();

	/*for (int i = 0; i < lineLength; i++)
	{
		if (isblank(inStr[i]))
		{
			i += 1;
			continue;
		}
			cout << inStr[i];*/
		
		//	std::string line_;
			//char chrIn[120];
		
			////This code works for getting lines from the text file
			//ifstream inputFile_("p1-test1.in");
		
			//if (inputFile_.is_open())
			//{

			//	while (getline(inputFile_, line_))
			//	{

			//		std::cout << line_ << endl;
			//		std::cout << line_.length() << endl;
			//	}
			//	inputFile_.close();
			//}
		
				
			//This code works for getting characters out of the text file, including spaces and new line. 
				char str[256];

				std::cout << "Enter the name of an existing text file: ";
				std::cin.get(str, 256);    // get c-string

				std::ifstream is(str);     // open file

				char c;
				while (is.get(c))          // loop getting single characters
					std::cout << c;

				is.close();                // close file

				return 0;
			

			
			//else
				//std::cout << "file is not open" << endl;








			/*ofstream myfile;
			myfile.open("example.txt");
			myfile << "Writing this to a file.\n";
			myfile.close();*/
		




		
		/*if (isalpha(inStr[i]) || ispunct(inStr[i])|| isblank(inStr[i]))
		{
			if (isblank(inStr[i]) == isblank(inStr[i + 1]))
				cout << "same";

			cout << outStr[i];*/
		}


	


	//outStr += inStr[1];

	//cout << outStr;
	//



	//vector<string> newS;

	//istringstream buf(inStr);
	//for (string word; buf >>word;)
	//{
	//	newS.push_back(word);
	//	cout <<"test";
	//}


	//const char s[2] = " ";
	//char *token;

	//token = strtok(inStr2, s);

	///* walk through other tokens */
	//while (token != NULL)
	//{
	//	printf(" %s\n", token);

	//	token = strtok_s(NULL, s);

//	std::cout << inStr2;
	//int i = 0;
	//for (sizeof(inStr2); i < 40; i++)
	//{
	//	
	//	
	//	
	//	
	//	
	//	
	//	std::cout << inStr2[i];
	//}

	


	//cout << inStr3[0][0];


	/*vector<string> testStr = { "Cocks" };
	
	testStr.insert ("Sucker";)

*/










	
