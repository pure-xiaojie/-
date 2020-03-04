/* Note:Your choice is C IDE */
#include <stdio.h>  
#include <string.h>  
  
int main()  
{  
    int i=0,j,k=0,u=0,t,g,x,d;  
    char a[80],b[80],c[80];  
    gets(a);  
    gets(b);  
    gets(c);  
    while(a[i]!='\0')  
    {  
        x=1;  
        t=i;  
        for(j=0;j<strlen(b);j++)  
        {  
            if(a[i]==b[j])  
            k++;  
           i++;  
        }  
        i=t;  
        if(k==strlen(b))  
        {  
            u=1;  
            j=0;  
            if(strlen(b)==strlen(c))  
              for(j=0;j<strlen(b);j++)  
            {  
                a[i]=c[j];  
                i++;  
            }  
            else if(strlen(b)>strlen(c))  
            for(j=0;j<strlen(a);j++)  
            {  
                if(x)  
                for(g=0;g<strlen(c);g++)  
                {  
                    a[i]=c[g];  
                    i++;  
                    x=0;  
                    j=g;  
                }  
                a[i]=a[i+strlen(b)-strlen(c)];  
                i++;  
            }  
            else if(strlen(b)<strlen(c))  
            for(j=0;j<strlen(c);j++)  
            {  
                d=strlen(c)-strlen(b);  
                if(x)  
                for(g=strlen(a);g>i+d;g--)  
                {  
                    a[g+1]=a[g];  
                    x=0;  
                }  
                a[i]=c[j];  
                i++;  
            }  
        }  
        k=0;  
        i=t;  
        i++;  
    }  
    if(u)  
    printf("%s", a);  
    else  
    printf("NO\n");  
    return 0;  
}  