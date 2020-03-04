/* Note:Your choice is C IDE */
 
#include <stdio.h>
#include <string.h>
void main()
{
    char a[100],b[100],c[100],t1;
    int i,j,k,w,t[300];
    scanf("%s",a);
    for (i=0;i<256;i++) 
    t[i]=0;
    i=0;
    while (a[i])
     {
     	t[a[i]]++; 
     	i++;
     }
    for (i=j=0;i<256;i++)
        while (t[i]--)
          a[j++]=i;
    a[j]='\0';
    for(i=j=k=0;a[i]!='\0';i++)
        {
            if(isalpha(a[i]))
              b[j++]=a[i];
            if(isdigit(a[i]))
              c[k++]=a[i];
        }
    c[k]='\0';
    b[j]='\0';
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {t1=c[i];c[i]=c[j];c[j]=t1;}
    w=strlen(b)/2;
    for(i=0,j=0;i<w;i++)
       a[j++]=b[i];
    for(i=0;i<strlen(c);i++)
        a[j++]=c[i];
    for(i=w;i<=w*2;i++)
        a[j++]=b[i];
    a[j]='\0';
    puts(a);
 
    
}
