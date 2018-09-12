// Write a C++ program to print your personal details name, surname(single character), total marks, 
// gender(M/F), result(P/f) by taking input from the user.

#include <iostream>
using namespace std;
int main(){
	char name[80], surname[80], gender, result;
	int total_marks;
	cout << "Enter your details\n";
	cout << "Enter name: ";		cin >> name;
	cout << "Enter surname: ";		cin >> surname;
	cout << "Enter total_marks: ";		cin >> total_marks;
	cout << "Enter gender: ";		cin >> gender;
	cout << "Enter result: ";		cin >> result;

	cout << "Name is: " << name 
		<< ", surname is: " << surname 
		<< ", total marks are: " << total_marks 
		<< ", gender is: " << gender
		<< ", result is: " << result
		<< "\n";
}
