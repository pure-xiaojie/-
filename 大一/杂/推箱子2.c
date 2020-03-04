#include<stdio.h>
#include<windows.h>
int a[6][6]= { {1,1,1,1,1,1},
               {1,0,0,0,0,1},
               {1,0,2,0,0,1},
               {1,0,0,0,0,1},
               {1,0,0,0,0,1},
               {1,1,1,1,1,1}};
int x=2,y=2;
void show()
{
    int i,j;
    system("cls");
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
            if(a[i][j]==1)
                printf("¡ö");
            else if(a[i][j]==2)
                printf("¡â");
            else
                printf("  ");
        putchar('\n');
    }
}
  main()
 { show();
   char arrow;
   while(1)
   {
       arrow=getch();
       if(arrow=='d')
       {
         if(a[y][x+1]==0)
           x++;
       }
       if(arrow=='a')
       {
         if(a[y][x-1]==0)
           x--;
       }
       if(arrow=='w')
        {
         if(a[x][y-1]==0)
           y--;
       }
       if(arrow=='s')
       {
         if(a[x][y+1]==0)
           y++;
       }
    a[x][y]=2;
    show();
   }


    return 0;
 }
