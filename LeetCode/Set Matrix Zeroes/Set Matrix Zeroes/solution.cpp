#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //find the first zero
        int k = 0; //the row where zero first appears
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i<m ;i++){
            for (int j = 0; j < n;j++ ){
                if (matrix[i][j] == 0) {
                    k = i;
                    break;
                } 
                break;
            }
            
        }
        //use the row k to restore which column should be 0
        for (int i = k+1; i<m ;i++){
            bool isrowzero = false;
            for (int j = 0; j < n;j++ ){
                if (matrix[i][j]==0){
                    matrix[k][j]=0;
                    isrowzero = true;
                }
            }
            if (isrowzero) {
                for (int j = 0; j < n;j++ ){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 0; j < n;j++ ){
            if (matrix[k][j]==0){
                for (int i = 0; i<m ;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

int main(){
	vector<vector<int>> matrix(10,vector<int>(10,1));
	Solution test;
	test.setZeroes(matrix);
	return 0;
}