/* Note:Your choice is C IDE */
#include<stdio.h>
#include<string.h>
void main()
{
char a[100],b[100];
int i,j,len,k=0;
gets(a);
len=strlen(a);
for(i=0;i<len-1;i++)
for(j=i+1;j<len;j++)
if(a[j]==a[i]&&a[j]!='*')
b[k++]=a[j],a[j]='*';
for(i=0,j=0;i<len;i++)
if(a[i]!='*')
{
a[j]=a[i];
j++;
}
a[j]='\0';
puts(a);putchar('\n');
len=strlen(b);
for(i=0;i<len-1;i++)
{
for(j=k=i+1;j<len-1;j++)
if(b[j]!=b[i])
b[k++]=b[j];
b[k]='\0';
}
puts(b);
}
