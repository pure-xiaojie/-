/* Note:Your choice is C IDE */
#include<stdio.h>
#include<string.h>
void main()
{
 char c1[100],c2[100],c3[100];
 int i,j,t;

 gets(c1);

 gets(c2);
   
 scanf("%d",&i);
 t = i;
     for(j=0;c1[t] != '\0';j++,t++)
         c3[j] = c1[t];
         c3[j]='\0';
    for(j=0;j<strlen(c1);j++,i++)
         c1[i] = c2[j]; 
         strcat(c1,c3);
         c1[i] = '\0';
 printf("%s",c1);
}
