#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b,t = 1;
    cin >> a >> b;
    int n = 1;
    while(1)
    {
        int x;
        cin >> x;
        if(x == a && n == 1)
        {
            t = 0;
            printf("Bingo\n");
        }

        if(x < 0 && n < b )
        {
            printf("Game Over");
            t = 0;
        }
        else if(x < 0)
            break;
        else if(t)
        {
            if(x > a && n <= b)
                printf("Too big\n");
            else if(x > a)
            {
                printf("Game Over");
                t = 0;
            }


            if(x < a && n <= b)
                printf("Too small\n");
            else if(x < a)
            {
                printf("Game Over");
                t = 0;
            }

            if(x == a && n <= 3)
            {
                printf("Lucky You!\n");
                t = 0;
            }

            else if(x == a && n <= b)
            {
                printf("Good Guess!\n");
                t = 0;
            }

        }
        n++;


    }
    return 0;
}
