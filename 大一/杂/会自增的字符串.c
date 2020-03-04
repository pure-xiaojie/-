#include<stdio.h>
#include<string.h>

int p(char a[],char b[])
{
 int i=0,j=0,k=0;
 for(i=0;a[i];i++)
 {
  j=i;
  for(k=0;a[j]==b[k]&&b[k]&&a[j];j++,k++);
  if(!b[k])
   return 1;
 }
 return 0;
}

int main()
{
    char a[10000],b[10000],c[10000];
    int len1,len2,i,j,h=0;
    scanf("%s %s",a,b);
    len1=strlen(a);
    len2=strlen(b);
    if(len1<len2)
     {
       h=len2/len1+1;
       for(i=0;i<h;i++)
       strcat(c,a);
     }
    int s=len1<len2?p(c,b):p(a,b);
    if(s)
      printf("%d",h);
    else
      printf("%d",-1);
}

