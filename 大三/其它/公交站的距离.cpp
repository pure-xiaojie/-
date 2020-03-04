#include<bits/stdc++.h>

using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int len = distance.size();
    if(len == 0)
        return 0;
    int min1 = 0,min2 = 0;
    if(start < destination) {
        for (int i = start; i < destination; i++)
        {
            min1 += distance[i];
        }
        for (int i = start; i > 0; i--)
        {
            min2 += distance[i-1];
        }
        for (int i = len; i > destination; i--)
        {
            min2 += distance[i-1];
        }
    }
    else {
        for (int i = start; i > destination; i--)
        {
            min1 += distance[i-1];
        }
        for (int i = destination; i > 0; i--)
        {
            min2 += distance[(i-1)];
        }
        for (int i = len; i > start; i--)
        {
            min2 += distance[i-1];
        }
    }
    return min(min1,min2);
}

int main()
{
    int start,desti,num;

    int t = 5;
    while(t--) {
        vector<int> dis;
        while(cin >> num,num >= 0) {
            dis.push_back(num);
        }
        cin >> start >> desti;
        cout << distanceBetweenBusStops(dis,start,desti) << endl;
    }
    return 0;
}
