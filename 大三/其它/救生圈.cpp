#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int len = people.size();
    sort(people.begin(),people.end());
    int count = 0;
    for(int i = 0; i < len;) {
        if(people[i] + people[len-1] <= limit)
            i++;
        len--;
        count++;
    }
    return count;
}

int main()
{
    vector<int> num;
    num.push_back(3);
    num.push_back(5);
    num.push_back(3);
    num.push_back(4);
    cout << numRescueBoats(num,5) << endl;
    return 0;
}
