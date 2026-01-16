// 3330.找到初始输入字符串 I

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        // vector<int> num;
        // int sum = 0;
        int ans = 1;
        for (int i = 1; i < word.size(); ++i) {
            if(word[i] == word[i - 1]){
                // sum++;
                ans++;
            }
            // else{
            //     // num.push_back(sum);
            //     ans+=sum;
            //     sum = 0;
            // }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string str = "abbcccc";
    int ans = sol.possibleStringCount(str);
    cout << ans << endl;
    return 0;
}