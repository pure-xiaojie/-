/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
int main()
{  long fun(long a,long b);
   long int x1,x2,y1,y2,x,y;  
    scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);  
        y=y1-y2;  
        x=x1-x2;
        if(x<0) x=abs(x);
        if(y<0) y=abs(y);
        if(!x&&!y)
          printf("0");        
        else   
          printf("%lld",fun(x,y)-1);
 
 return 0;
}
long fun(long a,long b){  
    if(b==0)  
        return a;  
    else  
        return fun(b,a%b);  
}  
