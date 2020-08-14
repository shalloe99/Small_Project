//============================================================================
// Name        : Comand_Line_Argument.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
// cctype needed for tolower(char), toupper(char),
//    isupper(char) and islower(char) functions
#include <string>

using namespace std;

// Inverts the case of each character,
//    i.e. capital to lower case and vice versa
string invertCase(string word) {
    for (unsigned int i=0; i<word.length(); ++i) {
        if (isupper(word.at(i)))
            word.at(i) = tolower(word.at(i));
        else if (islower(word.at(i)))
            word.at(i) = toupper(word.at(i));
    }
    return word;
}

// the built in toupper only works for a single character, you'll write an
//   overloaded function that works for C++ Strings.
string toupper(string word) {
    // TODO: add code to convert all characters to uppercase
	for (unsigned int i=0; i<word.length(); ++i) {
	      word.at(i) = toupper(word.at(i));
	    }
    return word;
}

// the built in tolower only works for a single character, you'll write an
//   overloaded function that works for C++ Strings.
string tolower(string word) {
    // TODO: add code to convert all characters to lowercase
	for (unsigned int i=0; i<word.length(); ++i) {
	      word.at(i) = tolower(word.at(i));
		}
	    return word;
}

// outputs usage statement and exits program with an error
// angle braces <> for required parameters
// square braces [] for optional parameters
// ... for option to repeat previous
void printUsage(string programName) {
    cout << "Usage: " << programName << " [-u | -l] <term> [term] ..." << endl;
    exit(1); // exits from program from any function with an error
}

// this program outputs the parameters
//    in all upper case, all lower case, or inverts case.
// by default, it will invert case
// if the 2nd parameter is a flag i.e. starts with a '-'
//    -u or -U means make output uppercase
//    -l or -L means make output lowercase
// Minimum number of parameters is 2 (program_name Term [...])
int main(int argc, char* argv[]) {
    bool upper=false, lower=false;

    // TODO: add code to check if enough arguments and output usage statement if not
    if(argv[1] == NULL){
    	printUsage(argv[0]);
    }
    int startIndex = 1;
    // process optional flag
    if ('-' == argv[1][0]) { // check if 2nd argument is a flag
        // since this is a flag, increment starting index for processing terms
        startIndex++;
        // argv[1][1] is a char, so these are calls to toupper(char) in cctype
        if ('U' == toupper(argv[1][1])) { // check if flag is valid option
            upper = true;
        }
        else if ('L' == toupper(argv[1][1])) { // check if flag is valid option
            lower = true;
        }
        else { //invalid flag
            printUsage(argv[0]);
        }
    }
    // TODO: add code to check if any parameters left to process
    //   if there are no terms to process,
    //      then output usage statement and exit program
   /* if(argv[2] == NULL){
    	printUsage(argv[0]);
    }*/
    // process and output terms
    for (int i=startIndex; i<argc; ++i) {
        if (upper) {
            // argv[i] is a string, so this is a call to toupper(string)
            cout << toupper(argv[i]) << " ";
        }
        else if (lower) {
            // argv[i] is a string, so this is a call to tolower(string)
            cout << tolower(argv[i]) << " ";
        }
        else { // invert case
            cout << invertCase(argv[i]) << " ";
        }
    }
    cout << endl;
}
