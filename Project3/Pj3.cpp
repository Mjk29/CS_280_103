// #include "p2lex.h"
#include "p2lex.cpp"
#include <string>
#include <istream>
#include <fstream>
// #include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Tree
  {
    Tree *prev;
    Tree *left;
    Tree *right;
    Token token;
    int line;
  };


struct node {
  Tree tree;
  int data;
  struct node * next;
};

node *head = NULL;




void addNode(Token tok) {
  node *newNode = new node;
  newNode-> tree.token = tok;
  newNode->next = NULL;

  if(head == NULL) {
    head = newNode;
    return;
  }
  node *cur = head;
  while(cur) {
    if(cur->next == NULL) {
      cur->next = newNode;
      return;
    }
    cur = cur->next;
  }
}


void display() {
  struct node *list = head;
  while(list) {
    cout << list->data <<" ";
    list = list->next;
  }
  cout << endl;
}

int main(int argc, char *argv[])
{


  istream *in = &cin;
  fstream infile;

  bool  verbose;

  for( int i=1; i<argc; i++ ) 
    {
    
      if( in != &cin ) {
        cerr << "Too many file names specified" << endl;
        exit(1);      }
      infile.open(argv[i]);
      if( !infile.is_open() ) {
        cerr << "Could not open file named: " << argv[i] << endl;
        exit(1);
      }

      in = &infile;
    }
  

  Token  tok;
  Token doneTok(DONE,"");
  Token errTok(ERR,"");
  string  Error;

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





  return 0;
}