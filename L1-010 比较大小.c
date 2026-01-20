#include<stdio.h>
void max(int x,int y,int z)
{
    if(x<=y&&x<=z)
    {
        printf("%d->",x);
        if(y<=z)
        {
            printf("%d->%d",y,z);
        }
        else{
            printf("%d->%d",z,y);
        }
        return;
    }
    if(y<=x&&y<=z)
    {
        printf("%d->",y);
        if(x<=z)
        {
            printf("%d->%d",x,z);
        }
        else{
            printf("%d->%d",z,x);
        }
        return;
    }
    if(z<=x&&z<=y)
    {
        printf("%d->",z);
        if(x<=y)
        {
            printf("%d->%d",x,y);
        }
        else{
            printf("%d->%d",y,x);
        }
        return;
    }
}


int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    max(a,b,c);
    return 0;
}