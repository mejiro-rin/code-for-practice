// 3315. 构造最小位运算数组 II

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
            } else {
                // 利用性质：x | (x + 1) 会把 x 最低位的 0 变成 1
                // 对于奇数 n，找到其二进制末尾连续的 1，将其中最高位的 1 变成 0 即可得到最小的 x
                long long t = (long long)n + 1;
                ans.push_back(n - ((t & -t) >> 1));
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> nums = {708152587,378138253,696612107,843995171,377416939,511045259,683858689,337171363,220344211,144177239,486997853,290548319};
    vector<int> result = test.minBitwiseArray(nums);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}