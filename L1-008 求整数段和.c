#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c=b-a;
    int sum=0;
    int i=1;
    while(i<=c+1)
    {
        printf("%5d",a);
        sum=sum+a;
        a++;
        i++;
        for(int h=6;h<=c+1;h+=5){
            //if(i!=h)printf(" ");
            if(i==h)printf("\n");
        }  
    }
    printf("\n");
    printf("Sum = %d",sum);
    return 0;
}