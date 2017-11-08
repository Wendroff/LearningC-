#include<vector>
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int offensive_denfensive(int a, int b, int c, vector<vector<vector<int>>>& off_def){
	if ((a>3)||(b>5)||(c>7)||(a<0)||(b<0)||(c<0)){
		cout<<"illegal situation: ["<<a<<","<<b<<","<<c<<"]"<<endl;
		system("pause");
	}
	int win = 1; //先假定是后手必胜
	//拿第一行的子，可能出现的情况
	for(int i=0;i<=(a-1);++i){
		if (off_def[i][b][c]==2){
			off_def[i][b][c]=offensive_denfensive(i,b,c,off_def);
		}
		if (off_def[i][b][c]==1){//能到达后手必胜的局面，必是先手必胜
			win = 0;
			return win;
		}
	}
	//拿第二行的子，可能出现的情况
	for(int i=0;i<=(b-1);++i){
		if (off_def[a][i][c]==2){
			off_def[a][i][c]=offensive_denfensive(a,i,c,off_def);
		}
		if (off_def[a][i][c]==1){//能到达后手必胜的局面，必是先手必胜
			win = 0;
			return win;
		}
	}
	//拿第三行的子，可能出现的情况
	for(int i=0;i<=(c-1);++i){
		if (off_def[a][b][i]==2){
			off_def[a][b][i]=offensive_denfensive(a,b,i,off_def);
		}
		if (off_def[a][b][i]==1){//能到达后手必胜的局面，必是先手必胜
			win = 0;
			return win;
		}
	}
	//只能抵达先必胜的局面，则该局面后必胜
	win = 1;
	return win;
};

int main(){
	int a = 3;//第一排的棋子数
	int b = 5;//第二排的棋子数
	int c = 7;//第三排的棋子数
	//不同局面的状态：0：先手胜；1：后手胜；2：未计算
	vector<vector<vector<int>>> off_def(4,vector<vector<int>>(6,vector<int>(8,2))); 
	//cout<<off_def[2][4][6]<<endl;
	off_def[1][0][0] = 1;
	off_def[0][1][0] = 1;
	off_def[0][0][1] = 1;
	off_def[0][0][0] = 0;
	
	int win;
	win = offensive_denfensive(a,b,c,off_def);

	//输出后手必胜的所有情况
	ofstream output("output.dat");
	output<<"Enumerate all the situations that the defensive side must wins"<<endl;
	output<<"Line  1    2    3"<<endl;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				if (off_def[i][j][k]==1){
					output<<"    "<<i<<"  "<<j<<"  "<<k<<endl;
				}
			}
		}
	}
	output.close();
	return 0;
};