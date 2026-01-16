// 2943.最大化网格图中正方形空洞的面积

#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans = 0;
        int I = 1, J = 1;
        int maxI = 0, maxJ = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i = 0; i < hBars.size(); i++){
            if(hBars[i] > n + 2) break;
            if(i == hBars.size() - 1){
                maxI = max(maxI, I);
                break;
            }
            if(hBars[i + 1] - hBars[i] == 1){
                I++;
            }
            else{
                I = 1;
            }
            maxI = max(maxI, I);
        }
        for(int j = 0; j < vBars.size(); j++){
            // cout << vBars[j] << endl;
            if(vBars[j] > m + 2) break;
            if(j == vBars.size() - 1){
                maxJ = max(maxJ, J);
                break;
            }
            if(vBars[j + 1] - vBars[j] == 1){
                J++;
            }
            else{
                J = 1;
            }
            maxJ = max(maxJ, J);
        }

        ans = pow(min(maxI, maxJ) + 1, 2);
        return ans;
    }
};

int main(){
    Solution test;
    int n = 4, m = 40;
    vector<int> hBars = {5,3,2,4}, vBars ={36,41,6,34,33};
    // cout << hBars.size() << " " << vBars.size() << endl;
    // cout << hBars[0] << " " << hBars[1] << endl;
    cout << test.maximizeSquareHoleArea(n, m, hBars, vBars);
    return 0;
}