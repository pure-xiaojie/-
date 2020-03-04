/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
	int i;
	char man;
	for(man='A';man<='F';man++)
	 { 
	 	if((  (man=='B'||man=='A')+
	 	      (man!='C')+
	 	      (man!='D'&&man!='E'&&man!='F')+
	 	      (man=='D'||man=='E'||man=='F') )==1)	 	
	 printf("%c",man);
	 }
    
}