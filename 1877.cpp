// 1877. 数组中最大数对和的最小值

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0;
        for (int l = 0, r = nums.size() - 1LL; l <= r - 1; l++, r--)
            ans = max(ans, nums[l] + nums[r]);
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums = {3,5,2,3};
    int result = test.minPairSum(nums);
    cout << result << endl;
    return 0;
}
