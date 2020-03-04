#include<bits/stdc++.h>

using namespace std;

string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

string dayOfTheWeek(int day, int month, int year) {
    int sumday = (year - 1971)*365;
    for(int i = 1971; i < year; i++)
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            sumday += 1;

    int i;
    for(i = 1; i < month; i++)
        sumday += mon[i];
    if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && i > 2)
        sumday += 1;

    sumday += day;


    return week[(sumday+4)%7];
}

int main()
{
    int year,month,day;
    int t = 10;
    while(t--) {
    cin >> year >> month >> day;
    cout << dayOfTheWeek(day,month,year) << endl;
    }
    return 0;
}
