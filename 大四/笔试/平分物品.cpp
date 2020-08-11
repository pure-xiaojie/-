#include<bits/stdc++.h>

using namespace std;
int a[10000],n;
int res;

void dfs(int i, int s1, int s2, int delet) {
   if(i == n)
   {
       if(s1 == s2 && delet < res) {
            res = delet;
       }
       return;
   }

   dfs(i+1,s1+a[i],s2,delet);
   dfs(i+1,s1,s2+a[i],delet);
   dfs(i+1,s1,s2,delet+a[i]);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        res = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            res += a[i];
        }
        dfs(0,0,0,0);
        cout << res << endl;
    }
    return 0;
}
