#include<string>
#include<iostream>
#include"solution.h"
using namespace std;
int main(){
	string s;
	while(cin>>s){
		Solution sol;
		string reslut = sol.shortestPalindrome(s);
		cout << "input = " << s << endl;
		cout << "output = " << reslut << endl;
	}
	cin >> s;
};