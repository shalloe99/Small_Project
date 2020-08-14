/*
 * functions.h
 *
 *  Created on: Feb 25, 2019
 *      Author: zshaw
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <string>
#include <iostream>
	std::string removeSpace(std::string word);
	std::string removeCase(std::string word);
	std::string removeHyphen(std::string word);
	void printUsageInfo(std::string word);
	bool isPalindrome(std::string word,bool caseSense,bool spaceSense);
	bool isPalindromeR(std::string word);

#endif /* FUNCTIONS_H_ */
