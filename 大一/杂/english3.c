/* Note:Your choice is C IDE */
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i;
    char STR[100][20]={'\0'};
    while(~scanf("%d",&N))
    {
        for(i=0; i<N; i++)
        {
            scanf("%s",STR[i]);
        }
        for(i=0; i<N; i++)
        {
            if(!strcmp(STR[i],"fork"))            
                printf("fork ");
            
            if(!strcmp(STR[i],"knife"))            
                printf("knife ");
            
            if(!strcmp(STR[i],"chopsticks"))            
                printf("chopsticks ");
            
            if(!strcmp(STR[i],"bowl"))            
                printf("bowl ");
            
        }
        printf("\n");
    }
 
 return 0;
}
