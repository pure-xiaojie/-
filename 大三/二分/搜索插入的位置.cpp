#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0,right = numsSize-1;
    while(left <= right) {
        int x= (left+right)/2;
        if(nums[x] == target)
            return x;
        else if(nums[x] < target)
            left = x+1;
        else
            right = x-1;
    }
    return left;
}

int main() {
    int nums[4] = {1,3,5,6};
    cout << searchInsert(nums,4,7) << endl;
    return 0;
}
