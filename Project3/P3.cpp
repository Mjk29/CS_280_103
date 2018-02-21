// #include "p2lex.h"
#include "p2lex.cpp"
#include <string>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;


struct Tree 
	{
	
		public:
		Token tok;
		Tree *prev = NULL;
		Tree *left = NULL;
		Tree *right = NULL;
		int	lineN ;
};

	struct Tree *ParseTree = new Tree;



	void initTree(struct Tree *head, Token tok)
	{
		head -> tok = tok;
		head -> left = NULL;
		head -> right = NULL;

	}


void addTree(struct Tree *head, Token tok)
	{
		Tree *newTree = new Tree;
	}






int linenum = 0;
int globalErrorCount = 0;




void error(string msg)
	{
		// cout << linenum << ": " << msg << endl;
		++globalErrorCount;
	}




/// function prototypes
Tree *Program(std::vector<Token> tok);
Tree *StmtList(std::vector<Token> tok);
Tree *Stmt(std::vector<Token> tok);
Tree *Expr(istream *in);
Tree *Term(istream *in);
Tree *Primary(istream *in);
Tree *String(istream *in);
void PrintTree(Tree *temp);


Tree *Program(std::vector<Token> tok)
	{
		 StmtList(tok);
	}


Tree *StmtList(std::vector<Token> tok)
	{
		Stmt(tok);
	}




Tree *Stmt(std::vector<Token> tok)
	{
		
	if( tok.at(0).getTok() == PRINT ) 
	{

		Tree *temp = new Tree;
		temp = ParseTree;
		Tree *newTree = new Tree;
		newTree -> tok = tok.at(0);

		std::cout<<"TREE ADDR      : "<<ParseTree<<endl;
		std::cout<<"TREE PREV ADDR : "<<ParseTree -> prev<<endl;
		std::cout<<"TREE LEFT ADDR : "<<ParseTree -> left<<endl;
		std::cout<<"NERWTREE ADRR  : "<<ParseTree<<endl<<endl;

		if (ParseTree -> prev == 0 && ParseTree -> left == NULL)
			{
				std::cout<<"ASDSAD"<<endl;
			newTree -> prev = ParseTree;
			newTree -> left = newTree;
			ParseTree = newTree;
			return ParseTree;

			}





		while(ParseTree != NULL)
		{
			ParseTree = ParseTree -> left;
		}

		std::cout<<temp<<"xxxxxxxxxxxx";
		newTree -> prev = temp;
		temp -> left = newTree;



		tok.erase(tok.begin());


		
	}
}


void PrintTree(Tree *temp)
	{

			

	while (temp  != NULL)
		{
			std::cout<<"Tree tok is: "<<temp -> tok<<endl;
			std::cout<<"Tree   addr: "<<temp <<endl;
			std::cout<<"Tree L addr: "<<temp -> left<<endl;
			std::cout<<"Tree R addr: "<<temp -> right<<endl;
			std::cout<<"Tree prev  : "<<temp -> prev<<endl<<endl;
			temp = temp -> left;			
		}

	}

Tree *Expr(istream *in)
	{

	return 0;
	}


Tree *Term(istream *in)
	{
	return 0;
	}


Tree *Primary(istream *in)
	{
	
	}


Tree *String(istream *in)
	{



	return 0;
	}




int main(int argc, char *argv[])

{

	Token start;


	istream *in = &cin;
	fstream infile;

	bool	verbose;

	for( int i=1; i<argc; i++ ) 
		{
		
			if( in != &cin ) {
				cerr << "Too many file names specified" << endl;
				exit(1);			}
			infile.open(argv[i]);
			if( !infile.is_open() ) {
				cerr << "Could not open file named: " << argv[i] << endl;
				exit(1);
			}

			in = &infile;
		}


	Token	tok;
	Token	doneTok(DONE,"");
	Token	errTok(ERR,"");
	string 	Error;

	std::vector<Token> Tokens;

	bool SQB = 0;


	while( !((tok = getToken(in)) == doneTok) && !(tok == errTok) ) 
		{
			Tokens.push_back(tok);
			int LEC;

			if (tok.getTok() == 5)
				{
				SQB = !SQB;
				LEC = linenum;
				}
			if (tok.getTok() == 6) 
				{ 
				SQB = !SQB; 
				if (LEC != linenum)
				{
					std::string errorSt = "Empty string not permitted on line ";
					errorSt += std::to_string(linenum);
					error(errorSt);
				}	
				}

		
			if (SQB != 1 && tok.getTok() == 9)
			{
		
		 		Program(Tokens);

		 		Tokens.clear();
		 		}



		

		}
				PrintTree(ParseTree);

		
}

