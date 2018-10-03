// Write a program to return absolute value of variable types integer and float using function overloading
#include<iostream>
using namespace std;\
int absolute(int a){
	return (a > 0) ? a : -a;
}
float absolute(float a){
	return (a>0) ? a : -a;
}
	
int main(){
	int ino, choice;
	float fno;
	char ch;
	do{
		cout << "1--> Absolute value of an integer\n"
		<<	"2--> Absolute value of a float\n"
		<< "Enter your choice\n";
		cin >> choice;
		switch(choice){
			case 1 : cin >> ino;	cout << absolute(ino); break;
			case 2 : cin >> fno; 	cout << absolute(fno); break;
			default : cout << "Wrong choice";
			}
		cout << "\nDo you want to continue(y/n) :";
		cin >> ch;
	}while(ch == 'y' || ch == 'Y');
	return 0;
}
