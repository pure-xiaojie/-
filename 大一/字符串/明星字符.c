/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{
    char str1[255];
    int str2[255]= {0},i=0,j,s;
  
    while(gets(str1)!=NULL)
    {
        for(i=1; i<255; i++)
            str2[i]=0;
        i=0;
        while(str1[i]!='\0')
        {
            str2[str1[i]]++;
            i++;
        }
  
        for(i=65; i<=90; i++)
        {
            str2[i+32]=str2[i+32]+str2[i];
            str2[i]=0;
        }
        
        s=str2[1];
        j=1;
        for(i=1; i<255; i++)
        {
            if(s<str2[i])
            {
                s=str2[i];
                j=i;
            }
        }
        printf("%c %d\n",j,s);
    }
 return 0;
}
