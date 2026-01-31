// 744. 寻找比目标字母大的最小字母

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto c : letters) if(c > target) return c;
        return letters[0];
    }
};

int main(){
    Solution sol;
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << endl;

    return 0;
}