/* Note:Your choice is C IDE */
#include <stdio.h>
void main()
{
    int x[3][3]= {0};
    int i,j,k;
    x[0][0]=7;
    x[1][0]=8;
    x[2][0]=9;
    for (i=4; i<6; i++)
     for (j=4; j<7; j++)
       for (k=4; k<7; k++)
        {
          if ((i!=j&&i!=k&&j!=k)&&(15-i-x[0][0]!=15-j-x[1][0]&&15-i-x[0][0]!=15-k-x[2][0]&&15-j-x[1][0]!=15-k-x[2][0]))
           {
            x[0][1]=i;
            x[0][2]=15-7-i;
            x[1][1]=j;
            x[1][2]=15-8-j;
            x[2][1]=k;
            x[2][2]=15-9-k;
            }
        }
    for (i=0; i<3; i++)
    {  for (j=0; j<3; j++)
        {if (x[i][j]==1)
            {
               if(i==0)
                 printf("Z");
               else 
                   if (i==1)
                    printf("W");
                   else
                    printf("L");
            }
        }
    }

}
