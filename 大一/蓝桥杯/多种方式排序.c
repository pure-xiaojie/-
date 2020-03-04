#include"stdio.h"
void Sort1(int a[],int sizeOfA)//A²Ù×÷
{
    int i,j,t;
    for(i=0;i<sizeOfA-1;i++)
     for(j=i+1;j<sizeOfA;j++)
       if(a[i]<a[j])
    {
        t=a[i];a[i]=a[j];a[j]=t;
    }
    for(i=0;i<sizeOfA;i++)
        printf("%d ",a[i]);

}

void Sort2(int a[],int sizeOfA,int b[],int sizeOfB,int c[])
{
    int i,j,t=0,temp;
    for(i=0;i<sizeOfA;i++)
       c[t++]=a[i];
    for(i=0;i<sizeOfB;i++)
       c[t++]=b[i];

    for(i=0;i<t-1;i++)
     for(j=i+1;j<t;j++)
       if(c[i]<c[j])
    {
        temp=c[i];c[i]=c[j];c[j]=temp;
    }

}
void Sort3(char str[],int n)//C²Ù×÷
{
   int i,j;
   char t;
    for(i=0;i<n-1;i++)
     for(j=1;j<n;j++)
       if(str[i]<str[j])
    {
        t=str[i];str[i]=str[j];str[j]=t;
    }
}

void Display(int a[],int sizeOfA)
{
    int i;
    for(i=0;i<sizeOfA;i++)
        printf("%d ",a[i]);
}
void Display2(char str[],int n)
{

    int i;
    for(i=0;i<n;i++)
        printf("%c ",str[i]);
}


main()
{
    char ch;
    scanf("%c",&ch);
    if(ch=='A')
    {
        int i,n,a[10000];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        Sort1(a,n);
    }
    else
        if(ch=='B')
    {
        int a[1000],b[1000],c[10000],n,m,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        Sort2(a,n,b,m,c);
        Display(c,n+m);

    }
    else
     {
        char a[1000];
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%c",&a[i]);

        Sort3(a,n);
        Display2(a,n);

    }

}
