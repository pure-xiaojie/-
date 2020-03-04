/* Note:Your choice is C IDE */
#include<stdio.h>


void reduce(int a,int b)
{
	int i;
	if(a==0||b==0) {printf("%d",0);return 0;}
	if(a==b){printf("%d",1);return 0;}
	for(i=a;i>=a/2;i--)
		if(a%i==0 && b%i==0)
			break;
	printf("%d/%d\n", a/i, b/i);


}


void add(int a1, int b1, int a2, int b2){
	reduce(a1*b2+a2*b1, b1*b2);
}


void sub(int a1, int b1, int a2, int b2){
	reduce(a1*b2-a2*b1, b1*b2);
}




int main()
{
int a,b,c,d;
char o;
while(scanf("%d/%d%c%d/%d", &a,&b,&o,&c,&d)!=EOF)
 {if(o=='+')
  add(a, b, c, d);
 if(o=='-')
  sub(a, b, c, d );
 }
return 0;
}