#include<iostream>
#include<string>
#include<math.h>

using namespace std;

struct People
{
    string name;
    int number;
};
int main()
{
    People people[10000];
    int n, target, tp = 0, sum = 0, min = 100000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].number;
        sum += people[i].number;
    }
    target = (sum / n) / 2;

    for (int i = 0; i < n; i++)
    {
        int d = abs(people[i].number - target);
        if (min > d)
        {
            min = d;
            tp = i;
        }
    }

    cout << target << " " << people[tp].name;

    return 0;
}
