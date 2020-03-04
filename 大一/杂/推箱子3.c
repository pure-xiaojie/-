#include<stdio.h>
#include<stdio.h>

int a[6][6]={{1,1,1,1,1,1},
            {1,0,0,0,0,1},
            {1,0,0,0,0,1},
            {1,0,0,0,0,1},
            {1,0,0,0,0,1},
            {1,1,1,1,1,1}};
int x,y,bx,by;
void goback()
 {
     int i,j;
      for(i=0;i<6;i++)
       for(j=0;j<6;j++)
        a[i][j]=1;
      for(i=1;i<5;i++)
       for(j=1;j<5;j++)
        a[i][j]=0;
 }
void show_map()
{
    int i,j;
    bx=3;by=4;
    system("cls");
    a[y][x]=2;
    a[by][bx]=3;
    for(i=0;i<6;i++)
     {
      for(j=0;j<6;j++)
      {
         if(a[i][j]==1)
           printf("¡ö");
         if(a[i][j]==0)
           printf("  ");
         if(a[i][j]==2)
           printf("¡â");
         if(a[i][j]==3)
           printf("¡õ");

      }

     putchar('\n');
     }
}
void main()
{   char move;
    x=3;
    y=3;
    show_map();
    while(1)
    {
        show_map();
        move=getch();
        if(move=='w')
        {  if(a[y-1][x]==0)
             y--;
        }
        if(move=='s')
        {  if(a[y+1][x]==0)
            y++;
        }
        if(move=='a')
        { if(a[y][x-1]==0)
            x--;
        }
        if(move=='d')
        { if(a[y][x+1]==0)
            x++;
        }
        goback();
    }
}
