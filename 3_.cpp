// 3_无重复字符的最长子串

#include <iostream>
#include <string>
#include <map>
using namespace std;


//1.暴力破解法
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int len=0;
//         for(int i = 0; i < s.size(); i++){
//             map<int, int, greater<int>> mymap;
//             int j = i;
//             for(; j < s.size(); ++j){
//                 mymap[s[j]]++;
//                 if(mymap[s[j]] > 1){
                    
//                     break;
//                 }
//                 // if(mymap.begin()->second > 1){
//                 //     len = max(len, j - i);
//                 //     break;
//                 // }
//             }
//             len = max(len, j - i);
//         }
//         return len;
//     }
// };

//2.记录法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mp[26] = {-1};//记录上一次出现同一字符的坐标
        int key = 0;//记录空格数量
        int last = 0;//记录上一次发生重复的坐标，
        int max_len = 0;//记录当前最大长度
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){
                int num = s[i] - 'a';
                if(mp[num] == -1){
                    mp[num] = i;
                }
                else{
                    int len = i - last;
                    max_len = max(len, max_len); 
                    last = mp[num];
                    mp[num] = i;
                }
            }
            else key++; 
        }
        return max_len - key;
    }
};


int main() {
    Solution solution;
    string s = " ";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}