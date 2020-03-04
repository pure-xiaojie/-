#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node {
    char name[10];
    int year;
    int month;
    int day;
};

struct node a;
struct node maxDate;
struct node minDate;
int sum = 0;

bool cmp(node a,node b)
{
    if(a.year != b.year)
        return a.year < b.year;
    else if(a.month != b.month)
        return a.month < b.month;
    else if(a.day != b.day)
        return a.day < b.day;
}

void getsum() {
    sum++;
    maxDate = max(maxDate,a,cmp);
    minDate = min(minDate,a,cmp);
}

int main()
{
    int n,k = 0;
    cin >> n;
    while(n--) {
        scanf("%s %d/%d/%d",a.name,&a.year,&a.month,&a.day);
        if(k == 0)
        {
           maxDate = a;
           minDate = a;
           k = 1;
        }

        if(a.year > 1814 && a.year < 2014) {
            getsum();
        }
        else if(a.year == 1814) {
            if(a.month > 9)
                getsum();
            else if(a.month == 9 && a.day >= 6)
                getsum();
        }
        else if(a.year == 2014) {
            if(a.month < 9)
                getsum();
            else if(a.month == 9 && a.day <= 6)
                getsum();
        }

    }
    if(sum == 1)
        printf("%d %s %s",sum,minDate.name , minDate.name);
    else
        printf("%d %s %s",sum,minDate.name , maxDate.name);

    return 0;
}
