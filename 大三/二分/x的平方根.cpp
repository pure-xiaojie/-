#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int mySqrt(int x) {
   if(x == 0 || x == 1)
      return x;
   long long left = 1, right = x;
   int res;
   while(left <= right) {
     long long t = (left+right)/2;
     if(t == x/t)
        return t;
     else if(t < x/t) {
        left = t+1;
        res = t;
     }
     else
        right = t-1;
   }
   return res;
}

int main()
{
    int n;
    cin >> n;
    int t=  mySqrt(n);
    cout << t;
    return 0;
}
