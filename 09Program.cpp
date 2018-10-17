// Program to perform string operations using operator overloading 
// = ==,<,> +
#include<iostream>
#include<string>
using namespace std;
class String{
	
public:
	string s;
	String(string a){s = a;}
	string getstring(){return s;}
	String operator +(String b){
		String ans;
		int i, j;
		
		for( i = 0; i < s.size(); i++){
			(ans.s).push_back(s[i]);
		}
		for( j = 0; j < b.s.size(); j++){
			ans.s.push_back(b.s[j]);
		}
		return ans;
	}
	// copy
	String operator=(String b){
		String ans(string s);
		int i;
		for(i = 0; i < s.size(); i++){
			ans.s[i] = s[i];
		}
		
		return ans;
	}	
	// equality
	bool operator==(String b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] != s[i])return false;
		}
		return true;
	}	
	// less than
	bool operator==(String b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] > s[i])return false;
		}
		return true;
	}	

	// greater than
	bool operator==(String b){
		int i;
		for( i = 0; i < b.s.size(); i++){
			if(b.s[i] < s[i])return false;
		}
		return true;
	}	

}
int main(){
	string a, b;
	cout << "Enter two strings\n";
	cin >> a >> b;
	String A(a), B(b);
	String C = A+B, D = A;
	bool e = (A == B);
	cout << A.getstring() << "\n" 
		<< B.getstring() << "\n" 
		<< C.getstring() << "\n"
		<< D.getstring() << "\n"
		<< e << "\n";

}