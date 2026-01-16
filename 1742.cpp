// 1742.盒子中小球的最大数量

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int arr[46] = {0};
        for(int i = lowLimit; i <= highLimit; ++i){
            int num = i, sum = 0;
            while(num){
                sum = sum + (num % 10);
                num/=10;
            }
            arr[sum]++;
        }
        int Max = 0;
        for(int temp : arr){
            if(temp > Max){
                Max = temp;
            }
        }
        return Max;
    }
};

int main(){
    Solution test;
    // 示例测试
    return 0;
}