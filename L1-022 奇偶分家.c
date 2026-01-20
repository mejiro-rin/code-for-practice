#include<stdio.h>
#define MAX_N 1000

typedef struct{
    int a;
}A;

int main()
{
    int N;
    scanf("%d",&N);
    A shu[MAX_N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&shu[i].a);
    }
    int d=0,s=0;
    for(int n=0;n<N;n++)
    {
        // printf("%d",shu[n].a);
        int y=shu[n].a%2;
        if(y==0)
        {
            s=s+1;
        }
        else
        {
            d=d+1;
        }
    }
    printf("%d %d",d,s);
    return 0;
}