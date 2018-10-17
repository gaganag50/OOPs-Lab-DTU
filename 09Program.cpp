// Program to perform MyString operations using operator overloading 
// = ==,<,> +
#include<iostream>
#include<string>
using namespace std;

class MyString{
	
public:
	string s;
	MyString(string a){
		for(int i = 0; i < a.size(); ++i)
			s.push_back(a[i]);
	}

	string getMyString(){
		return s;
	}

	MyString operator +(MyString b){
		MyString ans(s);
		int j;
		for( j = 0; j < b.s.size(); j++){
			ans.s.push_back(b.s[j]);
		}
		return ans;
	}
	
	void operator =(MyString b){
		
		int i;
		for(i = 0; i < b.s.size(); i++){
			s[i] = b.s[i];
		}
		
	}	
	// // equality
	bool operator==(MyString b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] != s[i])return false;
		}
		return true;
	}	
	// less than
	bool operator <(MyString b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] < s[i])return false;
			else if (b.s[i] > s[i])return true;
		}
		return true;
	}	

	// greater than
	bool operator >(MyString b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] > s[i])return false;
			else if(b.s[i] < s[i])return true;
		}
		return true;
	}	

};
int main(){
	string a, b;
	cout << "Enter two strings\n";
	cin >> a >> b;
	MyString A(a), B(b);
	MyString C = A+B, D = A;
	bool e = (A == B), f = (A<B), g = (A>B);
	cout << "First string: " << A.getMyString() << "\n" 
		<< "Second string: " <<B.getMyString() << "\n" 
		<< "First string + Second string: " <<C.getMyString() << "\n"
		<< "D = A " << D.getMyString() << "\n"
		<< "A == B " << e << "\n"
		<< "A < B " << f << "\n"
		<< "A > B " << g << "\n";

}