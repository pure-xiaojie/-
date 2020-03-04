/* Note:Your choice is C IDE */
#include<stdio.h>  
#include<string.h>  
char a[1000001],b[1000001];  
int main()  
{  
    int n,i,j,p,cnt,len1,len2,sum;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%s",a);  
        scanf("%s",b);  
        len1=strlen(a);  
        len2=len1-1;  
        p=i=j=cnt=0;  
        while(i<len1&&j<len2)  
        {  
            if(a[i]!=b[j])  
            {  
                p=i; 
                cnt++;   
                if(cnt>1)   
                    break;  
                i++; 
            }  
            else  
            {i++;j++;}  
  
        }  
        if(cnt>1)
            printf("0\n");  
        sum=0; 
        if(cnt==0)  
        {  
            for(i=len1-2;i>=0;i--) 
            {  
                if(a[i]==a[len1-1])  
                    sum++;   
                else  
                    break;  
            }  
            printf("%d\n",sum+1);  
            for(j=i+2;j<=len1;j++) 
              printf("%d ",j);  
            printf("\n");  
        }  
        else if(cnt==1)  
        {  
            for(i=p-1;i>=0;i--) 
            {  
                if(a[i]==a[p])  
                    sum++;  
                else break;  
            }  
            printf("%d\n",sum+1);  
            for(j=i+2;j<=p+1;j++)  
               printf("%d ",j);  
            printf("\n");  
        }  
    }  
    return 0;  
}  