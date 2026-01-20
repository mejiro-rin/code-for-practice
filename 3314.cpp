// 3314. 构造最小位运算数组 I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            // 如果是偶数 → 无解
            if (n % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            
            // 从 n/2 开始往下找（因为 ans[i] 一定 ≤ n/2）
            bool found = false;
            for (int x = 0; x <= n; ++x) {
                if ((x | (x + 1)) == n) {
                    ans.push_back(x);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums = {2,3,5,7};
    vector<int> result = test.minBitwiseArray(nums);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}