#include<stdio.h>
int main()
{
    int h,m=0;
    scanf("%d:%d",&h,&m);
    if((h>12&&h<24)||(h==12&&m!=0))
    {
        h=h-12;
        if(m>0)
        {
            h=h+1;
        }
        for(int i=0;i<h;i++)
        {
            printf("Dang");
        }
    }
    else
    {
        printf("Only ");
        if(h<10)
        {
            printf("0");
        }
        printf("%d:",h);
        if(m<10)
        {
            printf("0");
        }
        printf("%d.  Too early to Dang.",m);
    }
    return 0;
}