#include<stdio.h>
int main()
{
    int year, mon, day;
    int month[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(~scanf("%d-%d-%d", &year, &mon, &day))
    {
        int  n=0, i, count=0;
        if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) )
            n= 1;

        month[2] = month[2] + n;
        for (i = 1; i < mon; i++)
            count += month[i];

        count += day;
        printf("%d\n",count);
        month[2]=28;

    }

}
