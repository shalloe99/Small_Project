//============================================================================
// Name        : Bull_Cow.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
int takeDigit(){
	int digits;
	do{
		cout<<"Enter number of digits in code (3, 4 or 5): ";
		cin>>digits;
	}while(digits != 0 && digits != 3 && digits != 4 && digits != 5);
	return digits;
}
bool countDigit(int number, int digit){
	int count = 1;
	while(number%10 != number){
		count++;
		number /= 10;
	}
	if (count > digit){
		cout << "You can only enter "<< digit <<" digits."<<endl;
		return true;}
	else{
		return false;}
}
bool checkDuplicate(int array[],int digit){
	bool check = false;
	for(int i = 0;i < digit-1;i++){
		for(int j = i+1;j < digit;j++)
			if(array[i] == array[j])
				check = true;
	}
	if (check == true){
		cout << "Each number must be different."<<endl;
		return true;
	}else{
		return false;
	}
}
int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);
    // needed to autograde some test cases in Mimir
    int digit = 0 ,answer = 0,guess,i = 0, temp;
    int bull = 0, cow = 0;
    string userGuess = "";
    digit = takeDigit();
    int* answerArray = new int[digit];
    int* guessArray = new int[digit];
    int* resultArray = new int[digit];

    if(digit == 0){
    	// Assign the answer
    	cout << "Enter code: ";
    	cin >> answer;
    	do{
    		cout<<"Enter number of digits in code: ";
    		cin>>digit;
    	}while(digit != 0 && digit != 3 && digit != 4 && digit != 5);
       	for(int i = digit-1;i >= 0; i--){
    			answerArray[i] = answer % 10;
    			answer /= 10;
    		}
    	cout<<"Number to guess: ";
    	for(i = 0; i < digit-1; i++){
    	     cout<<answerArray[i]<<"-";
    	}cout<<answerArray[digit-1]<<endl;

    	while(bull != digit){
    		bull = 0,cow = 0;
    		for(i = 0; i < digit; i++){
    			resultArray[i] = 0;
    		}
			cout << "Enter Guess: ";
			cin >> guess;
			while(guess < 0){
				cout << "You must guess a positive integer"<<endl;
				cout << "Enter Guess: ";
				cin >> guess;
			}
			temp = guess;
			// check count digits being input
			// check if there is any duplicate
			for(int i = digit-1;i >= 0; i--){
				guessArray[i] = guess % 10;
				guess /= 10;
			}
			guess = temp;
			while(countDigit(guess,digit) or checkDuplicate(guessArray,digit)){
				cout <<"Enter Guess: ";
				cin >> guess;
				temp = guess;
				for(int i = digit-1;i >= 0; i--){
					 guessArray[i] = guess % 10;
					 guess /= 10;
				 }
				guess = temp;
			}
			//BULL & COW check
			for(int i = 0;i < digit; i++){
				if(guessArray[i] == answerArray[i]){
					resultArray[i] = 1;
					bull++;
				}
			}
		/*	for(i = 0; i < digit-1; i++){
			    		   cout<<answerArray[i]<<"-";
			    		 }cout<<answerArray[digit-1]<<endl;
			for(i = 0; i < digit-1; i++){
			      		   cout<<guessArray[i]<<"-";
			      		 }cout<<guessArray[digit-1]<<endl;
			for(i = 0; i < digit-1; i++){
						cout<<resultArray[i]<<"-";
			   }cout<<resultArray[digit-1]<<endl;*/

			for(int i = 0;i < digit; i++){
				if(resultArray[i] !=1){
					for(int j = 0; j < digit;j++){
						if(resultArray[i]!=1 && guessArray[i] == answerArray[j])
							cow++;
					}
				}
			}
			if(bull!=digit){
				cout << bull<<" bulls"<<endl;
				cout << cow<<" cows"<<endl;}
			else{
				continue;
			}
    	}
    		cout << digit <<" bulls... ";
    		for(i = 0; i < digit-1; i++){
    		   cout<<answerArray[i]<<"-";
    		 }cout<<answerArray[digit-1];
    		cout << " is correct!"<<endl;
    }else{
    	for(i = 0;i < digit;i++){
    		bool check = true;
    		int temp = 0;
    		do{
    			temp = rand() % 10;
    			check = true;
    			for(int j = 0; j< i; j++){
    				if(temp == answerArray[j])
    				{	check = false;
    					break;
    				}
    			}
    		}while(!check);
    		answerArray[i] = temp;
    	}

    /* cout<<"size of array: "<< sizeof(answerArray)/sizeof(answerArray[0]) <<endl;
    	cout<<"Enter number to guess: ";
    	cin>>guess;
    	int guessArray[digit];
    	for(int i = digit-1;i >= 0; i--){
    	    	guessArray[i] = guess % 10;
    	    	guess /= 10;
    	   	}*/
	// OUTPUT
    	for(i = 0; i < digit-1; i++){
    	        	cout<<answerArray[i]<<"-";
    	        }cout<<answerArray[digit-1];
    	cout<<endl;
    /*	for(i = 0; i < digit-1; i++){
    	        	cout<<guessArray[i]<<"-";
    	        }cout<<guessArray[digit-1];
    	cout << endl;*/
    }
    delete[] answerArray;
    delete[] guessArray;
    delete[] resultArray;
    return 0;
}
/*void assignDigits(int*& array,int number,int digit){
	delete[] array;
	array = new int[digit];
	cout << digit << endl;
	cout<<"size of array: "<< sizeof(array)/sizeof(int) <<endl;
	for(int i = digit-1;i >= 0; i--){
		array[i] = number % 10;
		number /= 10;
	//	cout<<array[i]<<" "<<number<<endl;
	}
	//delete[] array;
//	cout<<"--------------"<<endl;
}*/
/*	for(i = 0;i < digit;i++){
   		guess = guess*10 + stoi(userGuess.substr(i,i+1));
   		cout<<userGuess.substr(i*2,i*2+1)<<endl;
   	 //   guess = guess + stoi(userGuess.substr(i*2,i*2+1))*pow(10,digit-i-1);
     	}*/
/*  answer = 0;
   	int temp = rand() % 10;
   	bool check;
   	int size = 1;

   	answer = temp;
   	assignDigits(answerArray,temp,size);

   	for(i = 0;i < digit;i++){

   		for(int k = 0; k < size; k++){
   		    cout<<answerArray[k];
   		        }cout<<"-------"<<endl;

   		check = false;// check if duplicated
   		do{
   			temp = rand() % 10;
   			check = false;
   			for(int j = 0;j < i;j++){
   				cout<<"C H E C K I N G:: "<< temp <<"  "<<answerArray[j]<<endl;
   				if(temp == answerArray[j]){
   					check = true;
   				}
   			}
   		}while(check);
   		answer = answer*10 + temp;
   		size = i+1;
   		cout<<"SIZE:: "<<size<<"/ ::"<<i<<endl;
   		cout<<"size of array: "<<sizeof(answerArray)/sizeof(answerArray[0])<<endl;
   		assignDigits(answerArray,answer,size);
   	}
   	//assignDigits(answerArray,answer,digit);*/

