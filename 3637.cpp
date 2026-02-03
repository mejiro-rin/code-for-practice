// 3637. 三段式数组 I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int zhe = 0;
        int last = 0;
        // 初始为递增
        int greater = 1;
        for(int i = 1; i < nums.size(); i++) {
            // 超过两个反转
            if(zhe == 3) return false;
            // 与上一位的差
            int diff = nums[i] - nums[i - 1];
            // 递增则差大于0，递减小于0
            if(!((greater  == 1 && diff > 0) || (greater  == -1 && diff < 0))){
                // 强递增、递减，转折不能相邻
                if(diff == 0 || (zhe == 0 && i - last <= 1)) return false;
                zhe++;
                greater *= -1;
                last = i;
            }
        }
        if(zhe == 2) return true;
        return false;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,3,5,4,2,6};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {5,9,1,7};
    vector<int> nums = {2,4,3,3};
    cout << sol.isTrionic(nums) << endl;
    return 0;
}