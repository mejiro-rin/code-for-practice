// 3507. 移除最小数对使数组有序 I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // 必须保证数组至少有 2 个元素才能进行合并
        while (nums.size() > 1 && !isNonDecreasing(nums)) {
            long long minSum = LLONG_MAX; // 使用 long long 防止两个 1000 相加溢出
            int minIdx = -1;
            int n = static_cast<int>(nums.size());

            // 寻找和最小的相邻对
            for (int i = 0; i < n - 1; ++i) {
                long long currentSum = (long long)nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minIdx = i;
                }
            }

            // 执行合并
            if (minIdx != -1) {
                nums[minIdx] = (int)minSum;
                nums.erase(nums.begin() + minIdx + 1);
                operations++;
            } else {
                break; // 安全退出
            }
        }

        return operations;
    }
private:
    bool isNonDecreasing(const std::vector<int>& nums) {
        if (nums.size() <= 1) return true;
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<int> nums = {2,2,-1,3,-2,2,1,1,1,0,-1};
    int result = test.minimumPairRemoval(nums);
    cout << result << endl;
    return 0;
}