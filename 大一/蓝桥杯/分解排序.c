/* Note:Your choice is C IDE */
#include<stdio.h> 
#include<string.h> 
int main() 
{   int n;
    char s[20] ; 
    int i,t,j; 
    scanf("%s",s); 
    n=strlen(s); 
    for(j=0; j<n-1; j++) 
    { 
        { 
            for(i=0; i<n-1-j; i++) 
                if(s[i]>s[i+1]) 

                { 
                    t=s[i]; 
                    s[i]=s[i+1]; 
                    s[i+1]=t; 
                } 
        } 
    } 
    for(i=0; s[i]!='\0'; i++) 
        printf("%c ",s[i]); 
return 0;
} 