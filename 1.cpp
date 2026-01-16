// 1.两数之和

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j, i;
        for(i = 0; i < nums.size(); ++i){
            for(j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target) goto Find;
            }
        }
        Find:
        return {i, j};
    }
};