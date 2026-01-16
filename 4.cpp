// 4.寻找两个正序数组的中位数

#include <iostream>
#include <vector>
using namespace std;


//1.合并数组法
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = m + n, mid = k / 2;
        int i = 0, j = 0;
        vector<int> nums3;

        // 合并两个数组直到达到中位数位置
        while (nums3.size() <= mid) {
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                nums3.push_back(nums1[i++]);
            }
            else if (j < n) {
                nums3.push_back(nums2[j++]);
            }
        }

        // 根据总长度的奇偶性返回中位数
        if (k % 2 == 0) {
            return (nums3[mid - 1] + nums3[mid]) / 2.0;
        }
        else {
            return nums3[mid];
        }
    }
};


// 2.双指针
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0;
//         int m = nums1.size(), n = nums2.size();
//         while((i + j + 1) < ((m + n) / 2)){
//             if(i == m || j == n) break;
//             if(nums1[i] < nums2[j]){
//                 i++;
//             }
//             else if(nums1[i] > nums2[j]){
//                 j++;
//             }
//             else{
//                 i++;
//                 j++;
//             }
//         }
//         if(i != m){
//             while((i + j + 1) < ((m + n) / 2)){
//                 i++;
//             }
//         }
//         else if(j != n){
//             while((i + j + 1) < ((m + n) / 2)){
//                 j++;
//             }
//         }
//         double ans = 0;
//         if((m + n) % 2 == 0){
//             ans = (nums1[i] + nums2[j]) / 2.0;
//         }
//         else{
//             ans = min(nums1[i], nums2[j]) * 1.0;
//         }
//         return ans;
//     }
// };



int main() {
    Solution solution;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}