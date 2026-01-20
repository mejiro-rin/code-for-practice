#include<stdio.h>
#include<string.h>
int main()
{
    char T[10]={'0','1','2','3','4','5','6','7','8','9'};
    char P[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char I[100];
    char A[10]={'-'};
    scanf("%s",I);
    int l=0;
    l=strlen(I);
    //printf("%d",l);
    if(I[0]==A[0])
    {
        printf("fu");
    }
    for(int i=0;i<l;i++)//i为输入内容的序号
    {
        if(i>0)
        {
            printf(" ");    
        }
        for(int n=0;n<10;n++)
        {
            if(I[i]==T[n])
            {
                printf("%s",P[n]);
            }
        }
    }
    return 0;
}