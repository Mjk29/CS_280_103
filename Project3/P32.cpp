#include <fstream>
#include <iostream>
#include <iomanip>
#include <iomanip>

#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::ofstream;



bool A(void);
bool E(void);
bool O(void);
bool P(void);
bool U(void);
bool I(void);
bool C(void);
bool L(void);
bool D(void);

string s;

int main(int argc, char *argv[]) {

    ifstream fin;
	fin.open("input.txt");

if (!fin) {
        cout << "Unable to open file";
       return 0; // terminate with error
    }

    while (getline(fin,s)) {
        cout << "String read from file:  " << s  << endl;
	string news=s;
    if (A() && s.size() == 1) {
	cout<< "The string: "<< news << endl;
        cout  << " is in the language " << endl;
    }
    else {
        cout<< "The string"<< news<< endl;
        cout  << " is not in the language " << endl;
    
    }


    }




//}


//get string from command line
//else{

  //  s = argc == 2 ? argv[1] : "";

   // if (A() && s == "") {
   //     cout << "The string \"" << (argc == 2 ? argv[1] : "") << "\" is in the language" << endl;
    //}
  //  else {
       // cout << "The string \"" << (argc == 2 ? argv[1] : "") << "\" is not in the language" << endl;
  //  }
//}
fin.close();

    return 0;
}

bool A(void) {
	string x=s;
    if (I()) {

        if (s[0] == '=') {
            s = s.substr(1);
            if (E()) {
                return true;
            }
        }
    }
	s=x;
	 if (E() ){
		return true;
	}	
        return false;
    }
    

bool E(void) {
        if (P()) {
                while (O()) {
                	if (P()){
						
                	
                	}
                	else return false;
                }
			 
      		  	  return true;
            	 
		}
        return false;
    }



bool O(void) { 

	if (s[0] == '+') {
              s = s.substr(1);
              return true;
    }
    	  else if (s[0] == '-') {
      s = s.substr(1);
              return true;
    }
    	  else if (s[0] == '*') {
              s = s.substr(1);
              return true;
    }	
    	  else if (s[0] == '/') {
               s = s.substr(1);   		  
    		  return true;  
    }     
    	  else if (s[0] == '*') {
              s = s.substr(1);
    		  if (s[0] == '*') {
               s = s.substr(1);       		  
        		  return true;
    		  }
    	  }
		return false;
    }

bool P(void){

	if (I()){
    		return true;
    	}
    	else if (L()){
    		return true;
    	}
    	else if (U()){
    		if(I()){
    			return true;
    		}
       		else if(L()){
    			return true;
    		}
    	}
    	else if (s[0]== '(') {
               s = s.substr(1);   		  
            if (E()) {
                if (s[0] == ')') {
               s = s.substr(1);   		  
                    return true;
                }
            }
    	}
		return false;
    	
    }


bool U(void){
 	if (s[0] == '+') {
               s = s.substr(1);   		  
              return true;
    }
    	  else if (s[0] == '-') {
               s = s.substr(1);   		  
              return true;
    }
    	  else if (s[0]== '!') {
               s = s.substr(1);   		  
              return true;
    	
    }
		return false;
    	 }





bool I(void){
	if (C()){
     		if(I()){
     			return true;
     		}
			else{
				return true;
			}
     	}   
		return false; 
	}



bool C(void) {

    if ('a' <= s[0] && s[0] <= 'z') {
        s = s.substr(1);
        return true;
    }

    return false;
}


bool L(void){

	if (D()){
     		if(L()){
     			return true;
     		}
			else{
				return true;
			}
     	}   
		return false; 
	}



bool D(void) {

    if ('0' <= s[0] && s[0] <= '9') {
        s = s.substr(1);
        return true;
    }

    return false;
}