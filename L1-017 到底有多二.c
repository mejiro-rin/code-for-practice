#include<stdio.h>
#include<string.h>
int main()
{
    char A[100];
    scanf("%s",A);
    int l=strlen(A);
    int ou=1;
    int i=l-1;
    if((A[i]=='0')||(A[i]=='2')||(A[i]=='4')||(A[i]=='6')||A[i]=='8')
    {
        ou=2;
    }
    if(A[0]=='-')
    {
        l=l-1;
    }
    int er=0;
    for(int i=0;i<=l;i++)
    {
        if(A[i]=='2')
        {
            er=er+1;
        }
    }
     float fu=1.0;
    if(A[0]=='-'){
        fu=1.5;
    }
    double N=(double)er/(double)l*(double)fu*(double)ou;
    // printf("%f",N);
    double P=N*100;
    printf("%.2f%%",P);
    return 0;
}