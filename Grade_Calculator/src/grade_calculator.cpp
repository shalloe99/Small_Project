#include <iostream>
using namespace std;
float examTotal(int exam1,int exam2,int examf){
	float examAve;
		if (examf == -1) examAve = exam1*0.4+exam2*0.6;
		else{
			if((examf >=  exam1 )&& (examf >=exam2)) examAve = examf;
			else examAve =(exam1+exam2+examf)/3.0;}
		return examAve;
}
int activity(int grade){
	if(grade == 0 )grade = 0;
		else if(grade<85)grade +=15;
		else grade =100;
	return grade;
}
int main() {
	string syllabus;float bonus;
	int exam1,exam2,examf,zyParticipation,zyChallenge,clParticipation;
	// Syllabus
	cout<<"did you get 100% on the syllabus quiz [y/n]? "; cin>>syllabus;
	if(syllabus == "y" || syllabus == "Y")
	{// Exam
		cout<<"exam 1 grade [0-100]: "; cin>>exam1;
		cout<<"exam 2 grade [0-100]: "; cin>>exam2;
		cout<<"final exam grade [0-100, -1 to skip]: "; cin>>examf;
		float examAve = examTotal(exam1,exam2,examf);
	// Zybook
		cout<<"zybook participation (%): "; cin>>zyParticipation;
		cout<<"zybook challenge (%): "; cin>>zyChallenge;
		float zyTotal = activity(zyParticipation)*4.0/7.0+activity(zyChallenge)*3.0/7.0;
	//Class Participation
		cout<<"class participation (%): "; cin>>clParticipation;
		clParticipation = activity(clParticipation);
	//HW
	int temp = 0, hwSum = 0, i = -1, missingHW = 0;float hwAve;// HW count initialized
	do{
		hwSum +=temp;i++;
		cout<<"homework " <<i+1<<" [0-100, -1 to end]: "; cin>>temp;
		if(temp == 0)missingHW++;
	}while(temp >= 0);
	if(i==0)hwAve = 0; else hwAve= hwSum/float(i);
	//Lab
	int labSum = 0; temp = 0; i = -1;float labAve;// Lab count initialized
	do{
		labSum +=temp; i++;
		cout<<"labwork "<<i+1<<" [0-100, -1 to end]: "; cin>>temp;
	}while(temp >= 0);
	if(i==0)labAve = 0; else labAve = labSum/float(i)+15;
	if(labAve >=100) labAve = 100;
	//Bonus
	cout<<"extra credit points [0-1]: "; cin>>bonus; cout<<endl;
	//Output
	cout<<"exams:               "<< examAve <<endl;
	cout<<"zybook activities:   "<< zyTotal <<endl;
	cout<<"class participation: "<<clParticipation<<endl;
	cout<<"homework:            "<< hwAve<<endl;
	cout<<"labwork:             "<< labAve <<endl;
	cout<<"extra credit:        "<<bonus<<endl<<endl;
	float gradeTotal = 0.5*examAve + zyTotal*0.07+clParticipation *0.03+ hwAve*0.35+ labAve*0.05+bonus;
	cout<<"numeric grade: "<< gradeTotal<<endl;
	if(examAve<60) cout<<"letter grade: D "<<endl;// if exam average < 60
	else if(missingHW>=2) cout<<"letter grade: F "<<endl; // if missing two hws
	else if(gradeTotal>=90) cout<<"letter grade:  A"<<endl;
	else if(gradeTotal>=80&&gradeTotal<90) cout<<"letter grade: B "<<endl;
	else if(gradeTotal>=70&&gradeTotal<80) cout<<"letter grade: C "<<endl;
	else if(gradeTotal>=60&&gradeTotal<70) cout<<"letter grade: D "<<endl;
	else if(gradeTotal<60) cout<<"letter grade: F "<<endl;
	}else{
		cout<<endl;
		cout<<"letter grade: F";
	}
	return 0;
}
