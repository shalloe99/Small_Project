//============================================================================
// Name        : Palindromes.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <string>
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
    bool caseSensitive= false, spaceSensitive = true,hyphenSensitive = false;
    if(argc < 2){
       	printUsageInfo(argv[0]);
       }
    int startIndex = 1;
    if(argv[1][0] == '-' and argc <3){
    	printUsageInfo(argv[0]);
    }
    string original;
    bool check = true;
    for (int i=startIndex; i<argc; ++i) {
    	// process optional flag
        if ('-' == argv[i][0] and check == true) { // check if 2nd argument is a flag
            startIndex++;
            int index = 1;
            if ('-' == toupper(argv[i][index])){
            	check = false;
            	hyphenSensitive = true;
            }else if ('C' == toupper(argv[i][index])) { // check if flag is valid option
            	caseSensitive = true;
            }
            else if ('S' == toupper(argv[i][index])) { // check if flag is valid option
            	spaceSensitive = false;
            }
            else { //invalid flag
               printUsageInfo(argv[0]);
            	}
    	}else{
        	if (argv[i] == NULL)
        		{cout<<"RUN"<<endl;
        		printUsageInfo(argv[0]);}
			original = argv[i];
			string temp = original;
			//cout << output << " "<<endl;
			if (hyphenSensitive == true){
				temp = removeHyphen(temp);
			}
			if (isPalindrome(temp,caseSensitive,spaceSensitive)){
			cout<< "\""+original +"\" is a palindrome."<<endl;
				}
			else{
			cout<< "\""+original +"\" is not a palindrome."<<endl;
			}

        }
    }
}
