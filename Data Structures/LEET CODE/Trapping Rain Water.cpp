#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>&heights) {
    int capacity = 0;
    int n = heights.size();
    vector<int>leftmax(n),rightmax(n);
    leftmax[0] = heights[0];
    rightmax[n-1] = heights[n-1];
    // calculating the max height from left -> right
    for (int i = 1 ; i < n ; i++) {
        leftmax[i] = max(leftmax[i-1],heights[i]);
    }
    // calculating the mex height from right to left
    for (int i = n-2 ; i >= 0 ; i--) {
        rightmax[i] = max(rightmax[i+1],heights[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        capacity = capacity + (min(leftmax[i], rightmax[i]) - heights[i]);
    }
    return capacity;
}
int main() {
vector<int>arr = {4,1,2,1,5};
    int res = trap(arr);
    cout << res;
    return 0;
}