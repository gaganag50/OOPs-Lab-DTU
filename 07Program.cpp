// Write. a c++ program to perform different arithmetic operation such as addition, subtraction, division, modulus and 
//multiplication using inline function.

#include<iostream>
using namespace std;
class ArithmeticOperations{
	int a, b;
	public:
		ArithmeticOperations(int no1, int no2){
			a = no1;
			b = no2;
		}
		int addition();
		int subtraction();
		float division();
		int modulus();
		int multiplication();
};
	
inline int ArithmeticOperations::addition(){
	return a + b;
}
inline int ArithmeticOperations::subtraction(){
	return a - b;
}
inline float ArithmeticOperations::division(){
	return float(a / b);
}
inline int ArithmeticOperations::modulus(){
	return a % b;
}
inline int ArithmeticOperations::multiplication(){
	return a * b;
}
int main(){
	ArithmeticOperations arithmeticOperations(10, 20);
	cout << "10 + 20: " << arithmeticOperations.addition() 
		<< "\n10 - 20: " << arithmeticOperations.subtraction() 
		<< "\n10 / 20: " << arithmeticOperations.division() 
		<< "\n10 % 20: " << arithmeticOperations.modulus()
		<< "\n10 * 20: " << arithmeticOperations.multiplication();
	return 0;
}
