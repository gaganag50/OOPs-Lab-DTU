// Write a program to accept the student detail such as name and 3 different marks by get_data()method and 
//display the name and average of marks using display() method. Define a friend class for calculating average 
//of marks using the method mark_avg().

#include<iostream>
#include <string>
using namespace std;
class student{
	string name;
	int marks[3];
	double avg;
public:
	void get_data(string Name, int Marks[3]){
		name = Name;
		marks[0] = Marks[0];
		marks[1] = Marks[1];
		marks[2] = Marks[2];
	}
	void display(){
		cout << "Name of the student is: " << name << " and marks obtained are: " 
				<< marks[0] << " " 
				<< marks[1] << " " 
				<< marks[2] << " " 
				<< " average is: " << avg << "\n"; 

	}
	friend void mark_avg(student &s);
};
void mark_avg(student &s){
	s.avg = (s.marks[0] + s.marks[1] + s.marks[2])/3.0;
}
int main(){
	string name;
	int marks[3];
	cout << "Enter the name of the student: ";
	cin >> name;
	cout << "Enter the marks of the student in 3 subjects\n";
	cin >> marks[0] >> marks[1] >> marks[2];
	student s;
	s.get_data(name, marks);
	mark_avg(s);
	s.display();
}