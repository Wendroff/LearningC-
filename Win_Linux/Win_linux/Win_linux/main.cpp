#include<iostream>
#ifdef _LINUX
#include<unistd.h>
#endif
using namespace std;

int main(){
#ifdef _WIN32
	cout<<"This is a Win32 system"<<endl;
	system("pause");
#endif
#ifdef _WIN64
	cout<<"This is a Win64 system"<<endl;
	system("pause");
#endif
#ifdef _LINUX
	cout<<"This is a Linux system"<<endl;
	sleep(100);
#endif



};