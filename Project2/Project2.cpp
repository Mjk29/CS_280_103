#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include "p2lex.h"




using namespace std;
//This is a working function for checking the commands for a -v and returning a bool as true if -v is in the command line
//this can be altered to include more commands
//dont delete
//This version works as an independent function
//the other version of this works as an in main function
//only difference is the function header, and having Verbose defined inside the function

bool checkVerbose(int argc,char* argv[])
	{
		bool Verbose;
		for (int i = 1; i < argc; ++i)
			if (argv[i][0] == '-'&& isalpha(argv[i][1]))
				if (argv[i][1]=='v'||argv[i][1]=='V')
					Verbose = true;
		return Verbose;
	}



string getFile(int argc, char* argv[])
{
	string fileName;
	for (int i = 1; i < argc; ++i)
		{
		if (argv[i][0] == '-')
			{
				if (i == argc)
				{
					std::cout<<"No File";
					break;
				}	
			i++;
			}
		if (isalpha(argv[i][0]))
			fileName = argv[i];
	return fileName;
		}
}




	std::vector<string> getTokens(string fileName)
	{
		//fileName = "test.txt";
		const char * fN = fileName.c_str();
		

		std::vector <std::string> tokens;
		std::string str;

		std::ifstream fin(fN);


		while(fin>>str)
			tokens.push_back(str);
		
		fin.close();
		return tokens;

		for (int i = 0; i < tokens.size(); ++i)
		{		
			std::cout<<tokens.at(i)<<' ';
		}

	}









int main(int argc, char* argv[])
	{

	bool Verbose;
	std::string fileName;
	std::vector<string> Tokens;

	Verbose = checkVerbose(argc, argv);

	fileName = getFile(argc,argv);

	Tokens = getTokens(fileName);

	//std::cout<<Tokens.at(0);


//	std::cout<<"test";

//This finds the amount of arguments in the command line
//THe nuimber is always greater than 1 evne with no commands
//This means running just the program is 1 argument, with a file would be 2, 
	//and a file and additional argument such as -v is 3

// if (argc ==0)
// {
// 	std::cout<<"not enough args";
// }
//std::cout<<argc;



//This outputs the first string in command line, 2 is second and so on. Not sure what 0 is
//argv is a char type, and for whatever reason the itterations are seperated by a space
//It seems that the 0 value for argv[0] is the directory the file is located in,
//in this instance its /home/secus/documents/project2
//Im assuming that ths can be used to relocate the directory and find files somewhere else.
//Currently this outputs all of the commands seperated by a space
//This will have to be changed to take these commands and preform a function
//Most likely, one of hte arguments will be a filename, and the second will be a mode
//This works as a test for the arguments	
//for (int i = 1; i < argc; ++i)
		//std::cout<<argv[i]<<' ';
//DONT DELETE THIS VERY IMPORTANT FOR TESTING


//This next segment is going to take the commands given
//Then it will check to see if one is a file, and one is a command
//The filename will be some string thatdoes not begin with a '-'
//The mode will be a two character idenifier begining witha '-' and the second char will be a letter
//First i need to check for hte individual characters in the command

//std::cout<<argv[1][1];

//My assumption waS CORRect for this, the character arry can be accessed by a double array
//I can use this to check for a '-'



//For this program there are a few things to look for with the mode command
//accept at most one command
//This shold be easy, if there are more than one command, ill only accept the first one and discard the rest
//The second this is to check for '-v'	which is verbose mode.
// in Verbose mode, the program should print each token that it recognises
//So I will have to print any tokens that are also in the .h file
//should be easy to implement

//For this function Ill only check for number of commands, and if one is present
//As I saw in class, the command can be in the front or back of the filename
//I think Ill have this function set a bool operator to TRUE if -v is inputed
//This way, ill be able to output tokens later in the program if bool = True


// bool Verbose = false;

// bool checkVerbose(int argc,char argv)
// 	{
// for (int i = 1; i < argc; ++i)
// 	if (argv[i][0] == '-'&& isalpha(argv[i][1]))
// 			if (argv[i][1]=='v')
// 				bool Verbose = true;
// 	return Verbose;
// 		}


//This code successfully sets a bool opetrator to TRUE when there is a -char in the command line
//The code is setup to work for any alpha char, however I only care about -v at this point, so Ill change it a bit
//Ill add a ine inside hte function to chek fo specific characters, so if I need to change the code later to bemore inclusive its easy
//After adding an if v line, the code work successfully, so now ill hcange it to be a function

	// Verbose = checkVerbose(argc, argv);
			
//std::cout<<"Verbose mode is "<< Verbose;	

//The function successfully works, and this above function call checksfor -v and returns a TRUE to the bool Verbose

	


//This took so fucking long to figure out but I finally got it
/////////////////////////////////////////////////////
	////////////////////////////////////////////


// 	fileName = getFile(argc,argv);
// //fileName = "test.txt";
// const char * fN = fileName.c_str();



// 	std::vector <std::string> words;
// 	std::string str;

// 	std::ifstream fin(fN);


// 	while(fin>>str)
// 		words.push_back(str);
	
// 	fin.close();

// 	for (int i = 0; i < words.size(); ++i)
// 	{		
// 		std::cout<<words.at(i)<<' ';
// 	}


/////////////////////////////////////////////////////
	////////////////////////////////////////////
















// if (argc < 2) {
//       std::cout << "usage: " << argv[0] << " <filename>\n";
//       return 2;
//    }





//The next thing I need to do is preform some function on the argv other than checking for commands
//The command input should be some filename that is a text file
//I need to open this file and read it to memory

//Im going to pull some of this code from project 1, I should be able to read and tokenize the file


	// string FileN;
	// cout << "File name? ";
	// cin >> FileN;
//in the last project the filename was asked for, in this project its given in hte command line as one of the argv 
//the problem is that the command line will most likely have 2 arguments, 
//I know that if one of these arguments start with a '-' it will not be a filename
//so i can check ffor the command that starts with an alphanum which should be the filename

// string checkFilename(int argc,char argv)
	
// for (int i = 1; i < argc; ++i)
// 	{
// 	//this first bit checks for a '-' character, and skips to the next command, 
// 	//or breaks if at the end
// 	if (argv[i][0] == '-')
// 		{
// 			if (i == argc)
// 			{
// 				std::cout<<"No File";
// 				break;
// 			}	
// 		i++;
// 		}
// 	//this satement should now check for a filename
// 	//th elast statemement checked for a -chr
// 	//so any string that does not start with a - should be a filename

// 	if (isalpha(argv[i][0]))
// 		fileName = argv[i];

// 	}
	//This creates a variable fileName that contains a string of the inputed fileName
	//Im going to take this code and crate a function from it, it shoud return fileName to main
	
// 	//////////
// 	fileName = getFile(argc,argv);
// //////////////


	//std::cout<<fileName;



	// if (argv[i][1]=='v')
	// 			bool Verbose = true;
	// return Verbose;






	//I now have functions that check for command modifier, and for filename
	//Now I need to take that filename, open the file, and tokenize the contents 
	

	//FIRST To open the file, I have some code for the last project that does this, 

	







	// std::string lineIn;
	// std::string word;
	// std::vector<string> line;
	// std::vector<string> token;
	// std::vector<string> buffer;


	// //this code takes the text from the input file
	// //it does a getline on it, and pushes every line to a vector line
	// //the result is a vector where every instance is the next line starting at 0
	// //i need to somehow split this into words
	// while(std::getline(inFile,lineIn))
	// 	line.push_back(lineIn);

	// token.at(0) = "test";



	// //THis gives the character on a line
	// std::cout<<line.at(0).at(0);

	// //THis gives the character count for the current line in line
	 // std::cout<<line.at(1).size();

	// //to find the number of lines 
	// std::cout<<line.size();











	// //for ecery line
	// for (int i = 0; i < line.size(); ++i)
	// 	//for every chracter in the linj
	// 	//The problem is that I'm reading the lines from the file as a string
	// 	//but when I g through the lines trying to sperate them by a space 
	// 	//the characters are read as characters
	// 	//I can change the buffer to a char vector and it works
	// 	//howeer when I tr  push the buffer into a token sring vector it doesnt work
	// 	for (int j = 0; j < line.at(i).size(); ++j)
	// 	{
	// 		buffer.push_back(line.at(i).at(j));
	// 		// std::cout<<line.at(i).at(j);
	// 		if (isspace(line.at(i).at(j)))
	// 			token.push_back(buffer);


	// 			//std::cout<<"test ";
	// 		//  {	//this works when buffer and token are both char vector
	// 		//  	token.push_back(buffer.at(0));
	// 		//  	buffer.clear();
	// 		//  }
	// 		//  buffer.push_back(line.at(i).at(j));
	// 	}


	// //std::cout<<token.at(1);

	// for (int i = 0; i < buffer.size(); ++i)
	// {
	// 	std::cout<<buffer.at(i);
	// }
	// 	std::cout<<endl;




	// 	token.push_back("asd");
	// 	token.push_back("fgh");
		
	// 	std::cout<<token.at(1);

	// cout<<token.at(0);
	// word = line.at(0);
	// std::cout<<word;


	//THis is for checking the data type
	//the datatype of line.at(0) is
	//NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[Finished in 0.5s]
	//I dont know waht th fuck htis is or how to ue it
	//std::cout<<typeid(line.at(0)).name();





	//std::string buffer;
	//std::stringstream ss(line);
//	std::string tokens;

	// while(ss >> buffer)
	// 	tokens.push_back(buffer);

	// std:cout<<tokens.at(0);


}













// 	while(inFile)
// 	{
// 		string s;
// 		if (!getline(inFile,s))
// 			break;

// 		std::istringstream ss(s);
// 		vector<string> record;

// 		token.push_back(record);
// 	}

// if (!inFile.eof())
// 	cerr<<"endFile\n";

	



//std::cout<<token[1][0];


	//std::cout<<inFile;


	// std::stringstream buffer;
	// buffer << in.rdbuf();

	// std::string inStr = buffer.str();





