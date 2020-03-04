/* Note:Your choice is C IDE */
#include <stdio.h> 
#include <string.h> 

int main()  
{ 
    char s[50],t[50]; 
    int a,b,c,d; 
    while(gets(s)!=NULL) 
    { 
        if(sscanf(s, "%d.%d.%d.%d ",&a,&b,&c,&d)==4 &&   a>=0   &&   a<=255 &&   b>=0   &&   b<=255 &&   c>=0   &&   c<=255 &&   d>=0   &&   d<=255) 
        { 
            sprintf(t, "%d.%d.%d.%d",a,b,c,d);    
            if(strcmp(t,s)==0)  
            { 
                printf("YES\n");  
            }  
            else 
            { 
                printf("NO\n");  
            } 
        } 
        else  
        { 
            printf("NO\n"); 
        } 
    } 
    return 0;  
}  