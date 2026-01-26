// 1984. 学生分数的最小差值

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int min_diff = 1e9;
        for(int i = 0; i < len - k + 1; ++i){
            int j = i + k - 1;
            min_diff = min(min_diff, nums[j] - nums[i]);
        }
        return min_diff;
    }
};

int main(){
    Solution test;
    vector<int> nums = {9,4,1,7};
    int k = 2;
    int result = test.minimumDifference(nums, k);
    cout << result << endl;
    return 0;
}
