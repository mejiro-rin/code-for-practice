#include<stdio.h>
int main()
{
    int N=0;
    scanf("%d",&N);
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        int a=1;
        for(int n=1;n<=i;n++)
        {
            a=a*n;
        }
        sum=sum+a;
    }
    printf("%d",sum);
    return 0;
}