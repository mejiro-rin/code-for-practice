// 3047. 求交集区域内的最大正方形面积

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxRadius = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; ++i) {
            if(topRight[i][0] - bottomLeft[i][0] <= maxRadius || topRight[i][1] - bottomLeft[i][1] <= maxRadius){
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if(topRight[i][0] <= bottomLeft[j][0] || bottomLeft[i][0] >= topRight[j][0]
                || topRight[i][1] <= bottomLeft[j][1] || bottomLeft[i][1] >= topRight[j][1]){
                    continue;
                }
                int overlapSquare[2][2] = {{max(bottomLeft[i][0], bottomLeft[j][0]), max(bottomLeft[i][1], bottomLeft[j][1])},
                                            {min(topRight[i][0], topRight[j][0]), min(topRight[i][1], topRight[j][1])}};
                int overlapWidth = overlapSquare[1][0] - overlapSquare[0][0];
                int overlapHeight = overlapSquare[1][1] - overlapSquare[0][1];
                
                maxRadius = max(maxRadius, (long long)min(overlapWidth, overlapHeight));
            }
        }
        return 1LL * maxRadius * maxRadius;
    }
};

int main(){
    Solution test;
    vector<vector<int>> bottomLeft = {{1,36},{14,34},{29,34},{29,34},{17,18}};
    vector<vector<int>> topRight = {{48,41},{29,35},{48,40},{39,43},{39,32}};
    cout << test.largestSquareArea(bottomLeft, topRight);
    return 0;
}