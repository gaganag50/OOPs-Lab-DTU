// Create a class called 'Employee' that has "Empnumber" and "Empname" as data mebers and member functions getdata() 
// to input data display() to ouptut data. Write a main funciton to create an array of "Employee" objects. Accept
// and printt the details of at least 6 employees.

#include <iostream>
#include<cstring>
using namespace std;
class Employee{
	int Empnumber;
	char Empname[80];
public:
	void getdata(int emp_no, char emp_name[80]){
		Empnumber = emp_no;
		strcpy(Empname, emp_name);
		// Empname = emp_name;
	}
	void display(){
		cout << "Employee No is: " << Empnumber << " and Employee name is: "<< Empname << "\n";
	}
};
int main(){
	Employee emp;
	int emp_no;
	char emp_name[80];
	cout << "Enter name of the employee: ";
	cin >> emp_name ;
	cout << "Enter number of the employee: ";
	cin >> emp_no ;

	emp.getdata(emp_no, emp_name);
	emp.display();
}