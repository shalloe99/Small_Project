/*
 * functions.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: zshaw
 */
#include "functions.h"

std::string removeSpace(std::string word){
	std::string newWord = "";
	newWord += word.at(0);
	for (unsigned int i=1; i<word.length(); ++i) {
		if (word.at(i) !=' '){
			newWord += word.at(i);
		 }
		}
	return newWord;
}
std::string removeCase(std::string word){
	for (unsigned int i=0; i<word.length(); ++i) {
		word.at(i) = toupper(word.at(i));
		}
	return word;
}
std::string alNum(std::string word){
	std::string newWord = "";
	newWord += word.at(0);
	for (unsigned int i=1; i<word.length(); ++i) {
		if (isalnum(word.at(i)) or word.at(i) ==' '){
			newWord += word.at(i);
		 }
		}
	return newWord;
}
std::string removeHyphen(std::string word){
	std::string newWord;
	for (unsigned int i=0; i<word.length(); ++i) {
		if (word.at(i) !='-')
		newWord += word.at(i);
		}
	return newWord;
}
void printUsageInfo(std::string word) {
	// Credits From Comand_Line_Argument Lab
	std::cout <<"Usage: " << word << " [-c] [-s] string ..."<<std::endl;
	std::cout <<"  -c: turn on case sensitivity"<<std::endl;
	std::cout <<"  -s: turn off ignoring spaces"<<std::endl;
    exit(1); // exits from program from any function with an error
}

bool isPalindromeR(std::string word){
	int length = word.length();
		if (length <= 1){
			return true;
		}else{
			//std::cout<<word<<std::endl;
		if(length%2 != 0){//odd
				if(word.at(length/2-1) != word.at(length/2+1))
					{
					return false;
					}else{
				std::string newWord = word.substr(0,length/2-1)+word.substr(length/2+1,length);
				//std::cout<<"New Word: "<<word<<std::endl;
				return isPalindromeR(newWord);
					}
		}else{//even
			if(word.at(length/2-1) != word.at(length/2)){
				return false;
		}else{
		std::string newWord = word.substr(0,length/2-1)+word.substr(length/2+1,length);
		//std::cout<<"New Word: "<<word<<std::endl;
		return isPalindromeR(newWord);
		 }
		}
	}
}
bool isPalindrome(std::string word,bool caseSense,bool spaceSense){
			word = alNum(word);
			if (caseSense == false) {
				word = removeCase(word);
			}
			if (spaceSense == true) {
				word = removeSpace(word);
			}
			//std::cout<<word<<std::endl;
			return isPalindromeR(word);
}
//bool functions::isPalindrome(std::string word,int num){
//	int length = word.length();
//	if (length <= 1){
//		return true;
//	}else{
//		//std::cout<<"Palindrome function is running"<<std::endl;
//		//std::cout<<"length: "<<length<<std::endl;
//			if (num <= 0){
//				return true;
//			}
//			else{
//				if(word.at(num-1) != word.at(length-num))
//				{
//					return false;
//				}
//				else{
//					//std::cout<<word+ " "<<num<<std::endl;
//					num -= 1;
//					return functions::isPalindrome(word,num);
//				}
//			}
//	}
//}
/*bool functions::isPalindromeR(std::string word){
	int length = word.length();
	bool check = true;
	if (length <= 1){
		return true;
	}else{
		//std::cout<<"Palindrome function is running"<<std::endl;
		//std::cout<<"length: "<<length<<std::endl;
		for(int i = length/2;i>0;i--){
			if(word.at(i-1) != word.at(length-i))
				check = false;
		}
	}
	return check;
}*/


