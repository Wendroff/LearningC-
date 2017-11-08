#include<string>
#include<vector>
#include<iostream>

#include"solution.h"
using namespace std;


//class solution{
//public:
string Solution::shortestPalindrome(string s){
		string r = s;
		reverse(r.begin(),r.end());
		string t = s + "#" + r;
		vector<int> next(t.size(),0);
		for (int i=1; i<t.size();++i){
			int j = next[i-1];
			while(j>0 && t[i]!=t[j]) j=next[j-1];
			next[i] = (j += t[i]==t[j]);
		}




		cout<<"  t  = ";//<<endl;
		for (int i = 0; i < next.size(); ++i){
			cout<< t[i] << " ";
		}
		cout<<endl;
		cout<<"next = ";//<<endl;
		for (int i = 0; i < next.size(); ++i){

			cout<< next[i] << " ";
		}
		cout<<endl;
		return r.substr(0,s.size() - next.back()) + s;
	}


//};