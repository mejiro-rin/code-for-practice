// 3010. 将数组分成最小总代价的子数组 I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,12};
    cout << sol.minimumCost(nums) << endl;
    return 0;
}