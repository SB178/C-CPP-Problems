#include <stdio.h>
#include <stdlib.h>

int check(char* ptr,int n)
{
    int i=0;
    char*ptr2=ptr;
    
    while (*ptr2!='\0')
    {
        ptr2++;
    }
    ptr2--;
    fflush(stdin);
    
    while(i<n/2)
    {
        if(*ptr != *ptr2) return 0;
        ptr++;
        ptr2--;
        i++;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    char *ptr=(char*)malloc(sizeof(char)*(n+1));
    char *ptr2=ptr;
    
        fflush(stdin);
        scanf("%s",&(*ptr2));
        fflush(stdin);
        
    
    *ptr2='\0';
    ptr2=ptr;
    for(int i=0;*ptr2!='\0';i++)
    {
        fflush(stdin);
        printf("%c",(*ptr2));
        ptr2++;
    }
    if(check(ptr,n)==1) printf("\nPalindrome");
    else printf("\nNot a palindrome");
    return 0;
}