#include<stdio.h>
void main()
{
    int a,b,c,d;
    for(a=1; a<5; a++)

        for(b=1; b<5; b++)

            for(c=1; c<5; c++)

                for(d=1; d<5; d++)
                    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
                        if(b>a&&a!=1&&c>a&&b!=3)
                            printf("�ף�%d��\n�ң�%d��\n����%d��\n����%d��\n",a,b,c,d);

}
