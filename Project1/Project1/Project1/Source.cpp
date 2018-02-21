#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

//
//struct Token {
//	string Word;
//	int size = Word.size();
//	Token *next;
//};
//
//Token *start_ptr = NULL;
//
//
//void AddNode();



int main() {


	char c;
	string st;
	std::vector<char> charIn;
	auto lastElement = charIn.end();
	int lineSize = 60;
	string strIn;
	string line;
	string File;
	struct Line {
		int LineMax;
		std::string *Word;// = new std::string[length];
		int LineCurr;

	};

	//cout << "What file ? ";
//	cin >> File;

	string inStr ="p1-test2.in";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////							OPENS FILE AND DOWNLOADS DATA INTO VECTOR							//
	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::ifstream is(inStr);     // open file
	while (is.get(c))			//checks that not end of file
		charIn.push_back(c);	//pushes data to end of vector




	////////////////////////////////////////////////////////////////////////////////////////////////////
	////				CHECKS FOR NEWLINE, REPLACES SINGLE NEWLINE, SKIPS DOUBLE NEWLINE				//
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int i = 0;
	for (i; i != charIn.size(); ++i)
	{
		if (charIn.at(i) == '\n')						//checks for newline 
		{
			if (charIn.at(i) == '\n' && i + 1 != charIn.size() && charIn.at(i + 1) == '\n')	//If current element is newline and next element is newline and not end of file
			{
				i++;									//skips newline
				continue;
			}
			charIn.at(i) = 32;							//sets current element to blank space, which removes newline
		}
	}

	//	////////////////////////////////////////////////////////////////////////////////////////////////////
	//	////						PRINTS LINES IN LENGTH OF [lineSize] CHARACTERS							//
	//	////////////////////////////////////////////////////////////////////////////////////////////////////
	////
	//	int j = 0;
	//
	//	for (int i = 0; i < charIn.size(); i++)
	//	{
	//		if (charIn.at(i) == '\n')						//if current element is newline, reset line counter
	//			j = -1;										//reset line counter to -1, dont know why, but it works
	//
	//		if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
	//		{
	//			std::cout << endl;							//print current element
	//			j = 0;										//reset line to 0
	//		}
	//
	//		if (charIn.at(i) == 32 && j == 0)				//check if current element is space, and is first character in line
	//			i++;										//skip space at start of line
	//
	//		std::cout << charIn[i];							//prints current element
	//		j++;											//increase line counter
	//	}





		//////////////////////////////////////////////////////////////////////////////////////////////////
		//									OLD VERSIONS OF FUNCTIONS									//
		//////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////
		//			PRINTS LINES IN LENGTH OF [lineSize] CHARACTERS				NO LONGER NEEDED		//
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//int j = 0;
		//for (int i = 0; i < charIn.size(); i++)
		//{
		//	std::cout << charIn[i];							//prints current element

		//	if (charIn.at(i) == '\n')						//if current element is newline, reset line counter to 0
		//		j = 0;

		//	if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
		//		std::cout << endl;
		//	j++;											//increase line counter
		//}


		//////////////////////////////////////////////////////////////////////////////////////////////////
		//			CHECKS FOR NEWLINE AND REPLACES WITH SPACE CHARACTER		NO LONGER NEEDED		//
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//for (auto i = 0; i < charIn.size(); ++i)
		//{
		//	if (charIn.at(i) == '\n')				//checks for newline
		//		charIn[i] = 32;						//replaces current element with space character
		//}

		//////////////////////////////////////////////////////////////////////////////////////////////////
		//				PRINTS LINES IN LENGTH OF 40 CHARACTERS					NO LONGER NEEDED		//
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//for (int i = 0; i < charIn.size(); i++)
		//{
		//	std::cout << charIn[i];
		//	if (i != 0 && i%lineSize == 0)
		//		std::cout << endl;
		//}


		//////////////////////////////////////////////////////////////////////////////////////////////////
		//							CHECKS FOR NEWLINE AND DELETES ELEMENT		NO LONGER NEEDED		//
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//for (auto i = 0; i < size; ++i)
		//{
		//	if (charIn.at(i) == '\n')				//checks for newline
		//	{
		//		if (&charIn[i] == &charIn.back())	//checks if pointers to current itterator and to end itterator are the same
		//			break;								//determines if at end of vector, and stops
		//		charIn.erase(charIn.begin() + i);		//removes the current element 
		//	}
		//}
		//size = charIn.size();						//Must reset size after deletion or will bug out


		//////////////////////////////////////////////////////////////////////////////////////////////////
		//					PRINTS DATA FROM VECTOR TO COMMAND LINE				NO LONGER NEEDED		//
		//////////////////////////////////////////////////////////////////////////////////////////////////

		/*for (int i = 0; i < charIn.size(); i++)
			std::cout << charIn[i];*/


			//////////////////////////////////////////////////////////////////////////////////////////////////
			//								ABOVE THIS LINE WORKS DONT REMOVE								//
			//////////////////////////////////////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////////////////////////////////////
			//								BELOW THIS LINE IS TEST AREA									//
			//////////////////////////////////////////////////////////////////////////////////////////////////


	int j = 0;

	for (int i = 0; i < charIn.size(); i++)
	{
		if (j == 0 && charIn.at(i) == '.')
		{
			cout << "test";
		}


		if (charIn.at(i) == '\n')						//if current element is newline, reset line counter
			j = -1;										//reset line counter to -1, dont know why, but it works

		if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
		{
			std::cout << endl;							//print current element
			j = 0;										//reset line to 0
		}

		if (charIn.at(i) == 32 && j == 0)				//check if current element is space, and is first character in line
			i++;										//skip space at start of line

		std::cout << charIn[i];							//prints current element
		j++;											//increase line counter
	}




}
















	////////////////////////////////////////////////////////////////////////////////////////////////////
	////						PRINTS LINES IN LENGTH OF [lineSize] CHARACTERS							//
	////////////////////////////////////////////////////////////////////////////////////////////////////

//int j = 0;
//
//for (int i = 0; i < charIn.size(); i++)
//{
//	if (charIn.at(i) == '\n')						//if current element is newline, reset line counter
//		j = -1;										//reset line counter to -1, dont know why, but it works
//
//	if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
//	{
//		
//		if (charIn.at(i) != ' '  && charIn.at(i + 1) != ' ');
//		{
//			cout << '\n';
//		}
//		
//		std::cout << endl;							//print current element
//		j = 0;										//reset line to 0
//	}
//
//	if (charIn.at(i) == 32 && j == 0)				//check if current element is space, and is first character in line
//		i++;										//skip space at start of line
//
//	std::cout << charIn[i];							//prints current element
//	j++;											//increase line counter
//}
//













	//string temp;
	//vector<string> WordList;

	//for (int i = 0; i < charIn.size(); i++)
	//{
	//	
	//	
	//	
	//	cout << charIn.at(i);
	//	}
	//	
	//
	//








	//	for (int i = 0; i < charIn.size(); i++)
	//	{
	//		Start->Word = charIn.at(i);
	//		//cout << charIn.at(i);
	//	}
	//	
	//
	//	cout << Start->Word;
	//
	//
	//
	//}
	//
	//
	//
	//void AddToken()
	//{
	//
	//	Token *temp;
	//	Token *temp2;
	//	temp = new Token;
	//
	//	temp->next = NULL;
	//
	//	if (start_ptr == NULL)
	//		start_ptr = temp;
	//
	//	else
	//	{
	//		temp2 = start_ptr;
	//
	//		while (temp2->next != NULL)
	//			temp2 = temp2->next;
	//
	//		temp2->next = temp;
	//	}
	//}







	////////////////////////////////////////////////////////////////////////////////////////////////////
	////						PRINTS LINES IN LENGTH OF [lineSize] CHARACTERS							//
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//int j = 0;

	//for (int i = 0; i < charIn.size(); i++)
	//{
	//	if (charIn.at(i) == '\n')						//if current element is newline, reset line counter
	//		j = -1;										//reset line counter to -1, dont know why, but it works

	//	
	//	
	//	
	//	
	//	if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
	//	{
	//		
	//		if (charIn.at(i-1) != 32 && charIn.at(i) != 32)
	//			cout << endl<<charIn.at(i-1)<<j;



	//		std::cout << endl;							//print current element
	//		j = 0;										//reset line to 0
	//	}

	//	if (charIn.at(i) == 32 && j == 0)				//check if current element is space, and is first character in line
	//		i++;										//skip space at start of line

	//	std::cout << charIn[i];							//prints current element
	//	j++;											//increase line counter
	//}























	////////////////////////////////////////////////////////////////////////////////////////////////////
	////							OPENS FILE AND DOWNLOADS DATA INTO VECTOR							//
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//std::ifstream is(inStr);     // open file
	//while (is.get(st))			//checks that not end of file
	//strIn.push_back(st);	//pushes data to end of vector

	//std::vector<std::string> lines;
	//for (std::string line; std::getline(ifs, line); /**/)
	//	lines.push_back(line);

	//std::vector<std::string> my_arr;
	//std::ifstream dict_file("enable1.txt");
	//std::string line;
//
//std::string line;
//
//	while (std::getline(inStr, line))
//	{
//		std::string new_line;
//		new_line = line + "\n";
//		std::cout << new_line;
//		my_arr.push_back(new_line);
//	}
//
//
//







	/*std::vector<std::string> parts;
	std::vector<char>* pch;
	pch= strtok(charIn, " ");
	parts.push_back(pch);

	while (pch != NULL)
	{
		pch = strtok(NULL, " ");
		parts.push_back(pch);
	}
*/


//
//std::vector<char> str = "- This, a sample string.";
//char * pch;
//printf("Splitting string \"%s\" into tokens:\n", str);
//pch = strtok(str, " ,.-");
//while (pch != NULL)
//{
//	printf("%s\n", pch);
//	pch = strtok(NULL, " ,.-");
//}
//



////////////////////////////////////////////////////////////////////////
////////////		READS TEXT FROM FIL AND PUSHES IT ONTO STRING AS WORDS DOES NOT INCULDE SPACES OR NEWLIENS USELESS
/////////////////////////////////////////////////////////

//std::ifstream file (inStr);     // open file
//while (std::getline(file, strIn))
//{
//	std::istringstream iss(strIn);
//	
//	while (iss >> token)
//		line.append(token);


//}


//for (int i = 0; i < token.size(); i++)
//{
//	cout << token[i]<<endl;
//}
//












	////char str[] = "- This, a sample string.";			//string alrready allocated, charIN
	//std::vector<char> pch;
	////printf("Splitting string \"%s\" into tokens:\n", str);
	//for (int i = 0; i < charIn.size(); i++)
	//{

	//pch = strtok(charIn.at(i), " ,.-");
	//
	//
	///*	
	//	while (pch != NULL)
	//	{
	//		printf("%s\n", pch);
	//		pch = strtok(NULL, " ,.-");
	//	}*/
	//}




















	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//						PRINTS LINES IN LENGTH OF [lineSize] CHARACTERS							//
	//////////////////////////////////////////////////////////////////////////////////////////////////

	//int j = 0;

	//for (int i = 0; i < charIn.size(); i++)
	//{




	//	/*
	//	if (j == 0)
	//	{
	//		std::cout << "*" << charIn.at(i) << "*";
	//	}*/





	//	if (charIn.at(i) == '\n')						//if current element is newline, reset line counter
	//		j = -1;										//reset line counter to -1, dont know why, but it works


	//	if (j != 0 && j%lineSize == 0)					//if current line is length of lineSize, print newline
	//	{
	//		std::cout << endl;							//print current element
	//		j = 0;										//reset line to 0
	//	}

	//	if (charIn.at(i) == 32 && j == 0)				//check if current element is space, and is first character in line
	//		i++;										//skip space at start of line

	//	if (j%59== 0)									//detects first and last element of a line
	//	{


	//		std::cout << charIn[i] << j;							//prints current element
	//													//increase line counter
	//	}
	//	j++;
	//}
	













	//////////////////////////////////////////////////////////////////////////////////////////////////
	//cout << endl;	}						// MAIN END												//
	//////////////////////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	////				CHECKS FOR NEWLINE, REPLACES SINGLE NEWLINE, SKIPS DOUBLE NEWLINE				//
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//int i = 0;
	//for (i; i != charIn.size(); ++i)
	//{
	//	if (charIn.at(i) == '\n')						//checks for newline 
	//	{
	//		if (charIn.at(i) == '\n' && i + 1 != charIn.size() && charIn.at(i + 1) == '\n')	//If current element is newline and next element is newline and not end of file
	//		{
	//			i++;									//skips newline
	//			continue;
	//		}
	//		charIn.at(i) = 32;							//sets current element to blank space, which removes newline
	//	}
	//}



/*
	for (i=0; i != charIn.size(); ++i)
		std::cout << charIn.at(i);



		//if (i != 0 && i%lineSize == 0)										//checks for first character in vector, and for line length
		//	std::cout << endl;
	
		
		
		//if (charIn.at(i) == '\n' && charIn.at(i + 1) == '\n' && i != 0 && i + 1 != charIn.size())			// && i + 1 != charIn.size())					//checks for newline
		//{
		//	charIn[i] = 32;
		//	std::cout << charIn[i];
		//}
		//

	//	if (int i=0 != 0 && i%lineSize == 0)										//checks for first character in vector, and for line length
		//	std::cout << endl;


	//	if (charIn.at(i) == '\n')
	//	charIn[i] = 32;						//replaces current element with space character
	
	
	




	//////////////////////////////////////////////////////////////////////////////////////////////////
	//							PRINTS LINES IN LENGTH OF 40 CHARACTERS								//
	//////////////////////////////////////////////////////////////////////////////////////////////////

	//for (int i = 0; i < charIn.size(); i++)
	//{	
	//	std::cout << charIn[i];

	//	//if (charIn.at(i) == 32 && i + 1 != charIn.size() && charIn.at(i + 1) == 32)			//checks for end of file and double space
	//	//{
	//	//	//if (charIn.at(i + 2) == 32)						//NEED TO CHECK FOR MULTIPLE SPACES CURRENTLY BUGGED
	//	//	//{							
	//	//	//	cout << "test";
	//	//	//	break;
	//	//	//}
	//	//	cout << endl << endl;
	//	//}																//converts double space to double newline
	//	
	//	/*if (charIn.at(i) == 32 && i!=0 && charIn.at(i-1) ==32)		//HAVE TO CHECK FOR SPACES AT START OF LINE CURRENTYLY BUGGED
	//		cout << "asd";*/


	//	if (i != 0 && i%lineSize == 0)										//checks for first character in vector, and for line length
	//		std::cout << endl;												//stars new line
	//}















	
	//charIn.erase(charIn.begin()+i);

			//	charIn.erase(charIn.begin() + i);


				//Need to check if last element, will bug out if trying to delete
			/*if (vec->charIn[i] == charIn.end())
				{
					cout<<"test"<<endl;
					continue;
				}
	*/


				//while (is.get(c))          // loop getting single characters
				//if (isalpha(c))			//check for alphaneumeric characters

				/*if (c == '\n')			//check for newline and skip
					continue; */


					//is.close();                // close file

					//return 0;


					//if (isalpha(inStr[i]) || ispunct(inStr[i])|| isblank(inStr[i]))
					//{
					//if (isblank(inStr[i]) == isblank(inStr[i + 1]))
					//cout << "same";

					//cout << outStr[i];
