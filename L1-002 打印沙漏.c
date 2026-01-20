#include<stdio.h>
#include<math.h>
int main()
{
    int a,i = 0;
    int S;
    int N = 0;
    char inchar = 0;
    scanf("%d %c",&N,&inchar);
    //printf("%d %c",N,inchar);
    if (N<=1000&&N>1)
    {

        a = (N-1)/2;//a为用来计算分别分配给上下符号数
        int y1 = (N-1)%2;//第一次计算的余数
        if(a>=3)//大于等于三，能输出一行以上星号
        {
            int y2;
            while (1) 
            {
                i++;
                S = i*(6+(i-1)*2)/2;
            if(S > a)
            {
                i--;
                S=i*i+2*i;
                y2 = 2*(a-S);
                break;
            }
            }
            for(int i1=i;i1>0;i1--)//上半部分,i1为实时剩余行数
            {
                if(i1!=i)
                {
                    for(int k = i-i1;k>0;k--)
                    {
                        printf(" ");
                    }
                }
                for(int r=2*i1+1;r>0;r--)
                {
                    printf("%c",inchar);
                }
                printf("\n");
            }
            for(int i2=i;i2>0;i2--)
            {
                printf(" ");
            }
            printf("%c",inchar);
            printf("\n");
            for(int i3=i;i3>0;i3--)//下半部分,i3为实时剩余行数
            {
                if(i3!=1)
                {
                    for(int k = i3-1;k>0;k--)
                    {
                        printf(" ");
                    }
                }
                for(int r = 2*(i-i3+1)+1;r>0;r--)
                {
                    printf("%c",inchar);
                }
                printf("\n");
            }
            /*for(S1 = 3;S1 <= a;S1=S1+2)//上半部分，S为总个数
            {
                i1++;//行数+1
                if(i1>1)
                {
                    for(int k = 0;k<i1;k++)
                    {
                        printf(" ");
                    }
                }
                for(int b = 1;b<=S1;b++)//b为每行个数
                {
                    printf("%c",inchar);
                }
                int y2 = a-S1;
                
                printf("\n");
                printf("%d",y2);
            }*/
            printf("%d",y1+y2);
            //输出结束------------------------------
        }
        else//大于1但最多只能输出一行
        {
            printf("%c\n",inchar);
            printf("%d",2*a+y1);
        }
    }
    if(N==1)
    {
        printf("%c\n",inchar);
        printf("0");
    }
    while(1){
    }
    return 0;
}