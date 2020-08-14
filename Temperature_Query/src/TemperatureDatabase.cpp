#include "TemperatureDatabase.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	ifstream myfile;
	string id;
	int year,month;
	double temperature;
	myfile.open(filename);
	string line;
	stringstream ss;
	if(myfile.is_open()){
		while(myfile.good()){
			getline(myfile,line);
			//cout<<line<<endl;
			if(line=="")
				break;
			// Check nums of data in each line
			ss.str("");
			ss.clear();
			ss.str(line);
			ss>>id;
			if(ss.fail()){cout<<"not id string"<<endl;}
			ss>>year;
			if(ss.fail()){cout<<"not year int"<<endl;}
			ss>>month;
			if(ss.fail()){cout<<"not month int"<<endl;}
			ss>>temperature;
			if(ss.fail()){cout<<"not temperature double"<<endl;}
			if(ss.fail()){
				cout<<"Error: Other invalid input"<<endl;
				ss.str("");
				ss.clear();
				continue;
			}
			ss.str("");
			ss.clear();
			ss<<line;
			ss >> id;
			ss >> year;
			if(!(year> 1800 and year <2019)){
			 cout<<"Error: Invalid year "<<year<<endl;
			 continue;
			}
			ss >> month;
			//cout<<month<<" ";
			if(!(month>= 1 and month <=12)){
				cout<<"Error: Invalid month "<<month<<endl;
				continue;
			}
//			if((month-int(month))!=0){
//				cout<<"Error: Other invalid input--"<<endl;
//			}
			ss >> temperature;
			//cout<<temperature<<endl;
			if(!(temperature>=-50 and temperature<=50)){
				cout<<"Error: Invalid temperature "<<temperature<<endl;
				continue;
			}
			records.insert(id,year,month,temperature);
		}
		myfile.close();
	}else{
		cout<<"Error: Unable to open "+filename<<endl;
	}
	// Implement this function for part 1
}


void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
	ifstream myfile;
	string id;
	string mod;
	int start,end;
	myfile.open(filename);
	ofstream yourfile;
	//yourfile.open("src/result.txt");
	yourfile.open("result.dat");
	string line;
	stringstream ss;
	if(myfile.is_open()){
			while(myfile.good()){
				getline(myfile,line);
			//	cout<<line<<endl;
				if(line=="")
					break;
				// Check nums of data in each line
				ss.str("");
				ss.clear();
				ss.str(line);
				ss>>id;
				ss>>mod;
				ss>>start;
				ss>>end;
				if(ss.fail()){
					cout<<"Error: Other invalid query"<<endl;
					ss.str("");
					ss.clear();
					continue;
				}
	////////////////////Read Info/////////////////////////////
				ss.str("");
				ss.clear();
				ss<<line;
				ss >> id;
				ss >> mod;
				if (!(mod=="AVG" or mod =="MODE")){
					cout<<"Error: Unsupported query "<<mod<<endl;
					continue;
				}
				ss >> start;
				ss >> end;
				if((start > end) or !(start> 1800 and start <2019) or !(end> 1800 and end <2019)){
				 cout<<"Error: Invalid range "<<start<<"-"<<end<<endl;
				 	 continue;
				}

	/////////////////////Write Info////////////////////////////////
				Node* curr = records.getHead();
				int decision_year;
				vector<int> MODE;
				vector<int> TIMES;
				string decision_id;
				int index;
				double curr_temperature;
				double total_temperature = 0;
				int count = 0;
				while(curr != nullptr){
					decision_id = curr->data.id;
					decision_year = curr->data.year;
					curr_temperature = curr->data.temperature;
				//	cout<<decision_id<<" "<<decision_year<<" "<<curr_temperature<<endl;
					if(decision_id == id){
						if (decision_year>= start and decision_year<=end){
							total_temperature += curr_temperature;
							//MODE_START
							index = -1;
							for(int i = 0;i < MODE.size();i++){
								if(MODE.at(i) == round(curr_temperature)){
									index = i;
								}
							}
							if (index == -1){//not found
							 MODE.push_back(round(curr_temperature));
							 TIMES.push_back(0);
							}else{// found
							TIMES[index] += 1;
							}
							//MODE_END
							count++;
						}
					}
					curr = curr->next;
				}
				/// AVG
				if(mod == "AVG"){
					if (count == 0){
						yourfile<<id<<" "<<start<<" "<<end<<" "<<mod<<" unknown"<<endl;
					}else{
						double average = total_temperature/count;
						cout<<" average "<<fixed<<setprecision(5)<<average<<"----"<<"total "<<total_temperature<<endl;
						yourfile<<id<<" "<<start<<" "<<end<<" "<<mod<<" "<<average<<endl;
					}
				}else if(mod == "MODE"){ //MODE
					if (count == 0){
					yourfile<<id<<" "<<start<<" "<<end<<" "<<mod<<" unknown"<<endl;
				}else{
					int largest_element = TIMES[0]; //also let, first element is the biggest one
					for(int i = 1; i < TIMES.size(); i++)  //start iterating from the second element
					{
					    if(TIMES[i] > TIMES[largest_element])
					    {
					       largest_element = i;
					    }else if(TIMES[i] == TIMES[largest_element]){
					    	if(MODE[i]>MODE[largest_element])
					    		largest_element = i;
					    }
					}
					int mode_temperature = MODE[largest_element];
					yourfile<<id<<" "<<start<<" "<<end<<" "<<mod<<" "<<mode_temperature<<endl;
					}
				}

			  } yourfile.close();
			}else{
				cout<<"Error: Unable to open "+filename<<endl;
		}
}
