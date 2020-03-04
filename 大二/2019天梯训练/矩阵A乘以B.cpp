#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a[100][100],b[100][100],c[100][1000] = {0};
    int ca,ra,cb,rb;
    cin >> ca >> ra;
    for(int i = 0; i < ca; i++)
        for(int j = 0; j < ra; j++)
            cin >> a[i][j];

    cin >> cb >> rb;
    for(int i = 0; i < cb; i++)
        for(int j = 0; j < rb; j++)
            cin >> b[i][j];

    if(ra != cb)
        printf("Error: %d != %d",ra,cb);
    else
    {
        for(int i = 0; i < ca; i++)
            for(int j = 0; j < rb; j++)
            {
                for(int k = 0; k < cb; k++)
                    c[i][j] += a[i][k]*b[k][j];
            }

        cout << ca  << " "<< rb << endl;
        for(int i = 0; i < ca; i++)
        {
            int j;
            for(j = 0; j < rb-1; j++)
                printf("%d ",c[i][j]);
            printf("%d",c[i][j]);

            if(i < ca-1)
              printf("\n");
        }
    }
    return 0;
}
