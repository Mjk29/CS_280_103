#include "p2lex.h"
#include <list>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/////////
//// this class can be used to represent the parse result
//// the various different items that the parser might recognize can be
//// subclasses of ParseTree

class ParseTree
{
private:
	ParseTree *leftChild;
	ParseTree *rightChild;

	int whichLine;

public:
	ParseTree(ParseTree *left = 0, ParseTree *right = 0) : leftChild(left), rightChild(right)
	{
		whichLine = linenum;
	}

	int onWhichLine()
	{ return whichLine; }

	ParseTree *getLeft()
	{ return leftChild; }

	ParseTree *getRight()
	{ return rightChild; }

	void setLeft(ParseTree *leftChild)
	{ this->leftChild = leftChild; }

	void setRight(ParseTree *rightChild)
	{ this->rightChild = rightChild; }

};

//// for example, an integer...
class Integer : public ParseTree
{
private:
	Token iTok;

public:
	Integer(const Token &iTok) : ParseTree(), iTok(iTok)
	{}

	int getInteger()
	{ return stoi(iTok.getLexeme()); }
};


class PString : public ParseTree
{
private:
	Token t;

public:
	PString(const Token &t) : ParseTree(), t(t)
	{}

	std::string getString()
	{ return t.getLexeme(); }
};

class Identifier : public ParseTree
{
private:
	Token t;
public:
	Identifier(const Token t) : ParseTree(), t(t)
	{
	}

	std::string getIdentifier()
	{ return t.getLexeme(); }
};

class Operation : public ParseTree
{
private:
	Token t;
public:
	Operation(const Token t) : ParseTree(), t(t)
	{
	}

	std::string getOperation()
	{ return t.getLexeme(); }
};


int linenum = 0;
int globalErrorCount = 0;
std::map<std::string, bool> variable_names;

/// error handler
void error(string msg)
{
	cout << linenum << ": " << msg << endl;
	++globalErrorCount;
}

/// function prototypes
ParseTree *Program(istream &in);

ParseTree *StmtList(istream &in);

ParseTree *Stmt(istream &in);

ParseTree *Expr(istream &in);

ParseTree *Term(istream &in);

ParseTree *Primary(istream &in);

ParseTree *String(istream &in);

std::list<Token> buffer;

Token read(std::istream &in)
{
	Token t;
	if (!buffer.empty())
	{
		t = buffer.front();
		buffer.pop_front();

		std::cout << "Read " << t << " from stream\n";
		return t;
	}
	t = getToken(&in);
	std::cout << "Read " << t << " from stream\n";
	return t;
}

void push_back(Token t)
{
	buffer.push_back(t);
	std::cout << "Pushed " << t << " back\n";
}

bool has_more_tokens(std::istream &in)
{
	return !in.eof() || (!buffer.empty() && buffer.front().getTok() != EOF);
}

bool is_next(std::istream &in, TokenType type)
{
	if (!buffer.empty())
	{
		Token t = buffer.front();
		buffer.pop_front();
		buffer.push_back(t);
		return t.getTok() == type;
	}

	Token t = getToken(&in);
	buffer.push_back(t);
	return t.getTok() == type;
}

ParseTree *Program(istream &in)
{
	ParseTree *tree_head = new ParseTree;
	ParseTree *tree_head_copy = tree_head;
	tree_head->setLeft(StmtList(in));

	while (has_more_tokens(in))
	{
		ParseTree *left = new ParseTree;
		tree_head_copy->setRight(left);
		tree_head_copy = left;
		tree_head_copy->setLeft(StmtList(in));
	}

	return tree_head;
}


ParseTree *StmtList(istream &in)
{
	ParseTree *tree_head = new ParseTree;
	ParseTree *tree_head_copy = tree_head;
	tree_head->setLeft(Stmt(in));

	while (is_next(in, SET) || is_next(in, PRINT))
	{
		// Continually read statment lists

		ParseTree *left = new ParseTree;
		tree_head_copy->setRight(left);
		tree_head_copy = left;
		tree_head_copy->setLeft(Stmt(in));
	}

	return tree_head;
}


ParseTree *Stmt(istream &in)
{
	Token t = read(in);
	ParseTree *statment = new Operation(t);


	switch (t.getTok())
	{
		case PRINT:
		{
			ParseTree *expression = Expr(in);
			statment->setLeft(expression);
			if (!is_next(in, SC))
				error("Missing semicolon after print.");
			read(in);
			return statment;
		}
		case SET:
		{
			if (!is_next(in, ID))
			{
				error("Expected an ID, got something else.");
				return nullptr;
			}
			Token idToken = read(in);
			ParseTree *id = new Identifier(idToken);
			variable_names[idToken.getLexeme()] = true;
			ParseTree *expression = Expr(in);
			statment->setLeft(id);
			statment->setRight(expression);
			break;
		}
		default:
			error("Invalid statement.");
			return nullptr;
	}

	if (!is_next(in, SC))
	{
		error("Expected semi-colon, semi-colon not found.");
		return nullptr;
	}
	read(in);

	return 0;
}


ParseTree *Expr(istream &in)
{
	ParseTree *tree_head = new ParseTree;
	ParseTree *tree_head_copy = tree_head;
	tree_head->setLeft(Term(in));

	while (is_next(in, PLUS))
	{
		read(in);

		if (!is_next(in, ID) && !is_next(in, STR) && !is_next(in, INT) && !is_next(in, LPAREN))
		{
			error("Exprected ID|STR|INT|LPARREN");
			return nullptr;
		}

		ParseTree *left = new ParseTree;
		tree_head_copy->setRight(left);
		tree_head_copy = left;
		tree_head_copy->setLeft(Term(in));
	}

	return tree_head;
}


ParseTree *Term(istream &in)
{
	ParseTree *tree_head = new ParseTree;
	ParseTree *tree_head_copy = tree_head;
	tree_head->setLeft(Primary(in));

	while (is_next(in, STAR))
	{
		read(in);

		if (!is_next(in, ID) && !is_next(in, STR) && !is_next(in, INT) && !is_next(in, LPAREN))
			error("Exprected ID|STR|INT|LPARREN");

		ParseTree *left = new ParseTree;
		tree_head_copy->setRight(left);
		tree_head_copy = left;
		tree_head_copy->setLeft(Primary(in));
	}

	return tree_head;
}


ParseTree *Primary(istream &in)
{
	Token t = read(in);

	if (t.getTok() == ID)
	{
		if (!variable_names[t.getLexeme()])
		{
			error("Undeclared variable used");
		}
		return new Identifier(t);
	} else if (t.getTok() == INT)
	{
		return new Integer(t);
	} else if (t.getTok() == STR)
	{
		push_back(t);
		return String(in);
	} else if (t.getTok() == LPAREN)
	{
		ParseTree *ex = Expr(in);
		if (ex == nullptr)
			return nullptr;
		t = read(in);
		if (t.getTok() != RPAREN)
		{
			error("expected right parens");
			return nullptr;
		}

		return ex;
	}

	return nullptr;
}


ParseTree *String(istream &in)
{
	Token s = read(in);

	if (s.getTok() != STR)
	{
		error("Expected string");
		return nullptr;
	}

	if (s.getLexeme().length() == 0)
		error("Found zero length string");

	ParseTree *tree = new PString(s);
	ParseTree *tree_head_copy = tree;
	while (!is_next(in, RIGHTSQ))
	{
		read(in);

		ParseTree *left = new ParseTree;
		tree_head_copy->setRight(left);
		tree_head_copy = left;
		tree_head_copy->setLeft(Expr(in));
	}
	read(in);

	return tree;
}

main()
{
	ParseTree *prog = Program(cin);


	if (prog == 0 || globalErrorCount != 0)
	{
		cout << "Parse failed, exiting" << endl;
		return 0;
	}

	cout << "Success. Congrats!" << endl;
	return 0;
}