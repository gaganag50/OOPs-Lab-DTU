// Write a c++ program to swap two number by both call by value anad call by reference mechanism, 
// using two functions swap_value() and swap_reference() respectively, by getting the choice from the user and executing 
// the user's choice by switch case.

#include<iostream>
using namespace std;
void swap_reference(int &a , int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_value(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main(){
	int a, b;
	cout << "Enter 2 numbers: " ;
	cin >> a >> b;
	cout << "1--> Swap by using call by value mechanism\n";
	cout << "2--> Swap by using call by reference mechanism\n";
	int choice;
	cout << "Enter your choice: ";	cin >> choice;
	switch(choice){
		case 1 : swap_value(&a, &b);
				break;
		case 2 : swap_reference(a, b);
				break;
	}

	cout << "Swapped numbers are: ";
	cout << a << " " << b;
}