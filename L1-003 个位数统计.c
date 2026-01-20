#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,l;
    int sum;
    char S[10]={'0','1','2','3','4','5','6','7','8','9',};
    char T[1000]={0};
    scanf("%s",T);
    l=strlen(T);
    char c;
    for(i=0;i<10;i++)
    {
	    sum=0;
	    c=S[i];
	    for(j=0;j<l;j++)
        {
	        if(c==T[j])
            {
                sum++;  
	        }		
	    }
	if(sum!=0)
    {
        printf("%d:%d\n",i,sum);
	}
    }
}