// 1200. 最小绝对差

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        unordered_map<int, vector<vector<int>>> diff_map;
        for(int i = 0; i < len - 1; ++i){
            int diff = arr[i + 1] - arr[i];
            if(diff_map.size() == 0){
                diff_map.insert({diff, {{arr[i], arr[i + 1]}}});
                continue;
            }
            auto it = diff_map.begin();
            if(diff < it->first){
                diff_map.clear();
                diff_map.insert({diff, {{arr[i], arr[i + 1]}}});
            } else if(diff == it->first){
                it->second.push_back({arr[i], arr[i + 1]});
            }
        }
        return diff_map.begin()->second;
    }
};

int main(){
    Solution test;
    vector<int> arr = {4,2,1,3};
    vector<vector<int>> res = test.minimumAbsDifference(arr);
    for(auto &vec : res){
        for(auto &num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}