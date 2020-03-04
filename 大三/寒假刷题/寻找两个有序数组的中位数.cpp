#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;

    int i,j;
    for(i = 0, j = 0; i < n1 && j < n2;) {
        if(nums1[i] <= nums2[j]) {
            res.push_back(nums1[i]);
            i++;
        } else {
            res.push_back(nums2[j]);
            j++;
        }
    }
    while(i < n1) {
       res.push_back(nums1[i]);
       i++;
    }
    while(j < n2) {
       res.push_back(nums2[j]);
       j++;
    }
    if((n1 + n2) % 2 == 1)
        return res[(n1 + n2) / 2]*1.0;
    else
        return (res[(n1 + n2) / 2] + res[(n1 + n2) / 2 - 1]) / 2.0;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        vector<int> nums1, nums2;
        int n1,n2,t;
        cin >> n1 >> n2;
        for(int i = 0; i < n1; i++) {
            cin >> t;
            nums1.push_back(t);
        }
        for(int i = 0; i < n2; i++) {
            cin >> t;
            nums2.push_back(t);
        }
        cout << findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
