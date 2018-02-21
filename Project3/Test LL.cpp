#include "p2lex.h"
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <cstdlib>

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
 
  return 0;
}