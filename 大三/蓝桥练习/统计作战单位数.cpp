#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int numTeams(vector<int>& rating) {
    int len = rating.size();
    if(len < 3)
        return 0;

    int res = 0;
    for(int i = 0;i < len-2; i++) {
        for(int j = i+1; j < len-1; j++) {
            for(int k = j+1; k < len; k++) {
                if((rating[i] < rating[j] && rating[j] < rating[k])||
                   (rating[i] > rating[j] && rating[j] > rating[k]))
                    res++;
            }
        }
    }
    return res;
}

int main()
{
    int n,t;
    while(cin >> n) {
        vector<int> rat;
        for(int i = 0; i < n; i++) {
           cin >> t;
           rat.push_back(t);
        }

        cout << numTeams(rat) << endl;
    }
    return 0;
}
