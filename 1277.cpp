// 1277. 统计全为 1 的正方形子矩阵

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 1){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    res += dp[i][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution test;
    vector<vector<int>> matrix = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << test.countSquares(matrix);
    return 0;
}