#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct stone
{
    int pi,di;
    friend bool operator <(stone a, stone b)
    {
        if(a.di == b.di)
            return a.pi > b.pi;
        return a.di > b.di;
    }
}a;

int main()
{
    int T,t;
    priority_queue<stone>q;
    cin >> T;
    while(T--)
    {
      cin >> t;
      while(!q.empty())
        q.pop();
      for(int i = 0; i < t; i++)
      {
          cin >> a.di >> a.pi;
          q.push(a);
      }
      int sum = 0, num = 1;
      while(!q.empty())
      {
          if(num%2 != 0)
          {
              a=q.top();
              q.pop();
              a.di += a.pi;
              sum = a.di;
              q.push(a);
          }
          else
            q.pop();
          num++;
      }
      cout << q.top().di << endl;
    }
    return 0;
}
