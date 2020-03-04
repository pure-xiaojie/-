#include<stdio.h>
#include<windows.h>
#include<string.h>
int a[10][10]=
{
    {0,0,0,0,1,1,1,1,1 },
    {0,0,0,0,1,0,0,0,1 },
    {1,1,1,0,1,3,3,0,1 },
    {1,4,1,0,1,0,3,0,1 },
    {1,4,1,1,1,0,1,1,1 },
    {1,4,0,0,0,0,1,1 },
    {1,0,0,1,0,0,0,1 },
    {1,0,0,1,0,0,0,1 },
    {1,1,1,1,1,1,1,1 }
},b[10][10];

int x,y,bx,by,boxx=5,boxy=2,boxx1=6,boxy1=2,boxx2=6,boxy2=3;

void goback()
 {   int i,j;
     for(i=0;i<10;i++)
      for(j=0;j<10;j++)
       a[i][j]=b[i][j];
 }
void show_map()
{   goback();
    int i,j;

    system("cls");
    a[y][x]=2;
    a[boxy][boxx]=3;
    a[boxy1][boxx1]=3;
    a[boxy2][boxx2]=3;
    for(i=0;i<10;i++)
     {
      for(j=0;j<10;j++)
      {
         if(a[i][j]==1)
           printf("¡ö");
         if(a[i][j]==0)
           printf("  ");
         if(a[i][j]==2)
           printf("¡â");
         if(a[i][j]==3)
           printf("¡õ");
         if(a[i][j]==4)
          printf("¡ñ");


      }

     putchar('\n');
     }
}
void main()
{   int i ,j;
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    b[i][j]=a[i][j];

    char move;
    x=7;y=1;
    bx=2;by=3;
    a[by][bx]=3;

    show_map();
    while(1)
    {
        show_map();
        move=getch();
        if(move=='w')
        {  if(a[y-1][x]==0)
             y--;
           else if(y-1==boxy&&x==boxx&&a[y-2][x]==0)
           {
               y--;
               boxy--;
           }
        }
        if(move=='s')
        {  if(a[y+1][x]==0)
            y++;
           else if(y+1==boxy&&x==boxx&&a[y+2][x]==0)
           {
               y++;
               boxy++;
           }
        }
        if(move=='a')
        { if(a[y][x-1]==0)
            x--;
          else if(x-1==boxx&&y==boxy&&a[x-2][y]==0)
           {
               x--;
               boxx--;
           }
        }
        if(move=='d')
        { if(a[y][x+1]==0)
            x++;
          else if(x+1==boxx&&y==boxy&&a[x+2][y]==0)
           {
               x++;
               boxx++;
           }
        }

        goback();
    }
}
