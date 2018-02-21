#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cin;
using std::cerr;
using std::endl;

/*****************************************************************************/
namespace Lexer
{
    enum Token{
        NAME, NUMBER, END, PLUS='+', MINUS='-', MUL='*', DIV='/',
        PRINT=';', ASSIGN='=', LP='(', RP=')'
    };

    Token currToken;
    double numberValue;
    string stringValue;
    
    Token getToken();
}

/*****************************************************************************/
namespace Parser
{
    double prim(bool);
    double term(bool);
    double expr(bool);

    std::map<string,double> table;
    int noOfErrors;
    double error(const string& s);

    using Lexer::getToken;
    using Lexer::currToken;
    using Lexer::numberValue;
    using Lexer::stringValue;
}

/***************************************************************************/
/*
program:
    END
    expr_list END

expr_list:
    expression PRINT
    expression PRINT expr_list

expression:
    term + expression
    term - expression
    term

term:
    primary / term
    primary * term
    primary

primary:
    NUMBER
    NAME
    NAME = expression
    - primary
    ( expression )
*/
int main(int argc, char* argv[])
{
    while(cin)
    {
        //Put the first token
        Lexer::getToken(); 
        //
        // break out of while if the end token
        if(Lexer::currToken == Lexer::END) break;
        //
        // if current token is PRINT 
        if(Lexer::currToken == Lexer::PRINT) continue;
        //
        // call expr() without geting the next token to evaluate the expresion
        std::cout << Parser::expr(false) << std::endl;
    }
    return 0;
}

/*****************************************************************************/
// Lexer::getToken()
// The parser uses getToken() to get its input. The most recent call to 
// getToken is stored in the global variable currToken.
Lexer::Token Lexer::getToken()
{
    char ch =0;
    
    do
    {// skip white spaces except '\n'
        //
        // if hit the end of the stream return END token
        if(!cin.get(ch)) return currToken = END;

    }while(ch !='\n' && isspace(ch) );
    
    switch (ch)
    {
        // PRINT token: thismarkse the end of an expr_list
        case ';':
        case '\n':
            return currToken = PRINT;

        // Parentheses and operators are handled by returning 
        // their values.
        case '*': case '/': case '+': case '-':
        case '(': case ')': case '=':
            return currToken = Token(ch);

        // if the char represents the start of a number, push
        // it back into the stream and read the number into numberValue
        // and return NUMBER token
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin >> numberValue;
            return currToken = NUMBER;
        
        default: // NAME, Name =, or eror
            if (isalpha(ch))
            {
                // This allows you to store and retreave named values
                // eg enter pi = 3.1415926; and then you can use pi as
                // a value like pi * 2; willgive the answer 6.2831852 
                stringValue = ch;
                while (cin.get(ch) && isalnum(ch)) 
                    stringValue.push_back(ch); //build up the string
                
                // the char is not an alpha/numeric so push it back
                // for next time.
                cin.putback(ch);
                return currToken = NAME;
            }
            // if you are here you don't have a valid token
            // show an error and mark the end of the expr_list with PRINT
            error("Bad token");
            return currToken = PRINT;
    }
}

/*****************************************************************************/
// Parser::prim(bool get)
//
double Parser::prim(bool get)
{
     if (get) getToken();

     switch (currToken)
     {
        case Lexer::NUMBER:
        {
            double v = Lexer::numberValue;
            getToken();
            return v;
        }
        case Lexer::NAME:
        {
            double& v = table[stringValue];
            if(getToken() == Lexer::ASSIGN) 
                v = expr(true);
            return v;
        }
        case Lexer::MINUS:
            {
                return -prim(true);
            }
        case Lexer::LP:
            {
                double e = expr(true);
                if (currToken != Lexer::RP)
                    return error(") expected");
                getToken();
                return e;
            }
        default:
            return error("primary expected.");
     }
}

double Parser::term(bool get)
{
    double left = prim(get);

    for(;;)
    {
        switch (currToken)
        {
        case  Lexer::MUL:
            left *= prim(true);
            break;
        case Lexer::DIV:
            if (double d = prim(true))
            {
                left /= d;
                break;
            }
            return error("Divide by 0");
        default:
            return left;
        }
    }
}

///////////////////////////////////////
// Parser::expr(bool get)
// Input: bool get; Indicates whether the function
//                  needs to get the next token.
// The function handles the Addition and Subtraction
double Parser::expr(bool get)
{
    double left = term(get); 

    for(;;) //forever
    {
        switch (currToken)
        {
            case Lexer::PLUS:
                left += term(true);
                break;
            case Lexer::MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

double Parser::error(const string& s)
{
    noOfErrors++;
    cerr << "Error: " << s << endl;
    return 1;
}