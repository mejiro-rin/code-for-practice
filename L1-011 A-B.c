#include<stdio.h>
#include<string.h>
int main()
{
    char A[1000000];
    char B[1000000];
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    int l=strlen(B);
    A[strcspn(A, "\n")] = 0;
    B[strcspn(B, "\n")] = 0;
    for(int i=0;A[i]!='\0';i++)
    {
        int f=0;
        for(int n=0;n<l;n++)
        {
            if(A[i]==B[n])
            {
                f=1;
                break;
            }
        }
        if(!f)
        {
            printf("%c",A[i]);
        }
    }
    return 0;
}