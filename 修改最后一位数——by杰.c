#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%s",str);
    int l,i;
    l=strlen(str);

    char c;
    
    for(i=0;i<l-1;i++)
    {
    c=str[i];
    printf("%c",c);
    }
    
    char s=str[l-1];
    if(s=='1')
      {
       printf("0");
      }
      if(s=='0')
      {
       printf("1");
      }
    
    
    return 0;
}