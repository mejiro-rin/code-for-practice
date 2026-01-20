// 1895. 最大的幻方

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> dp_row (grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> dp_col (grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                dp_row[i][j] = grid[i][j] + (j > 0 ? dp_row[i][j - 1] : 0);
                dp_col[i][j] = grid[i][j] + (i > 0 ? dp_col[i - 1][j] : 0);
            }
        }
        int maxLen = 1;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                for(int len = 1; len + i <= grid.size() && len + j <= grid[0].size(); ++len){
                    if(isMagicSquare(grid, dp_row, dp_col, j, i, len)){
                        maxLen = max(maxLen, len);
                    }
                }
            }
        }
        return maxLen;
    }
private:
    bool isMagicSquare(const vector<vector<int>>& grid, const vector<vector<int>>& dp_row, const vector<vector<int>>& dp_col,int x, int y, int len){
        int sum = dp_row[y][x + len - 1] - (x > 0 ? dp_row[y][x - 1] : 0);
        int d1 = 0, d2 = 0;
        // 检查每一列，遍历行
        for(int i = 0; i < len; ++i){
            if(sum != dp_col[y + len - 1][x + i] - (y > 0 ? dp_col[y - 1][x + i] : 0)){
                return false;
            }
            if(sum != dp_row[y + i][x + len - 1] - (x > 0 ? dp_row[y + i][x - 1] : 0)){
                return false;
            }
            // 检查两条对角线
            d1 += grid[y + i][x + i];
            d2 += grid[y + i][x + len - 1 - i];
        }
        if(d1 != sum || d2 != sum) return false;

        return true;
    }
};

int main(){
    Solution test;
    vector<vector<int>> grid = {{1,17,15,17,5,16,8,9},{1,19,11,18,8,18,3,18},{6,6,5,8,3,15,6,11},{19,5,6,11,9,2,14,13},{12,16,16,15,14,18,10,7},{3,11,15,15,7,1,9,8},{15,5,11,17,18,20,14,17},{13,17,7,20,12,2,13,19}};
    cout << test.largestMagicSquare(grid);
    return 0;
}