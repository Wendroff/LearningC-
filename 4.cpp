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
	int win = 1; //�ȼٶ��Ǻ��ֱ�ʤ
	//�õ�һ�е��ӣ����ܳ��ֵ����
	for(int i=0;i<=(a-1);++i){
		if (off_def[i][b][c]==2){
			off_def[i][b][c]=offensive_denfensive(i,b,c,off_def);
		}
		if (off_def[i][b][c]==1){//�ܵ�����ֱ�ʤ�ľ��棬�������ֱ�ʤ
			win = 0;
			return win;
		}
	}
	//�õڶ��е��ӣ����ܳ��ֵ����
	for(int i=0;i<=(b-1);++i){
		if (off_def[a][i][c]==2){
			off_def[a][i][c]=offensive_denfensive(a,i,c,off_def);
		}
		if (off_def[a][i][c]==1){//�ܵ�����ֱ�ʤ�ľ��棬�������ֱ�ʤ
			win = 0;
			return win;
		}
	}
	//�õ����е��ӣ����ܳ��ֵ����
	for(int i=0;i<=(c-1);++i){
		if (off_def[a][b][i]==2){
			off_def[a][b][i]=offensive_denfensive(a,b,i,off_def);
		}
		if (off_def[a][b][i]==1){//�ܵ�����ֱ�ʤ�ľ��棬�������ֱ�ʤ
			win = 0;
			return win;
		}
	}
	//ֻ�ִܵ��ȱ�ʤ�ľ��棬��þ�����ʤ
	win = 1;
	return win;
};

int main(){
	int a = 3;//��һ�ŵ�������
	int b = 5;//�ڶ��ŵ�������
	int c = 7;//�����ŵ�������
	//��ͬ�����״̬��0������ʤ��1������ʤ��2��δ����
	vector<vector<vector<int>>> off_def(4,vector<vector<int>>(6,vector<int>(8,2))); 
	//cout<<off_def[2][4][6]<<endl;
	off_def[1][0][0] = 1;
	off_def[0][1][0] = 1;
	off_def[0][0][1] = 1;
	off_def[0][0][0] = 0;
	
	int win;
	win = offensive_denfensive(a,b,c,off_def);

	//������ֱ�ʤ���������
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