#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int a[55];
        int heap[3];
        heap[0] = heap[1] = heap[2] = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        //Î¬»¤Ð¡¶¥¶Ñ
        for(int i = 0; i < n; i++) {
            if(a[i] <= heap[0])
                heap[0] = a[i];
            else if(a[i] <= heap[1])
                heap[1] = a[i];
            else if(a[i] <= heap[2])
                heap[2] = a[i];
        }

        if(heap[2] == INT_MAX)
            cout << -1 << endl;
        else
            cout << heap[2] << endl;
    }
    return 0;
}
