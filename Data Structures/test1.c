#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>&height) {
    int tcapacity = 0;
    int max_element = INT_MIN;
    for (int i = 0 ; i < height.size(); i++) {
        int maxee = max(maxee,height[i]);
        if ((maxee - height[i+1]) < 0) continue;
        int tcapacity = tcapacity + ( maxee - height[i+1]);
    }
    int sol = tcapacity;
}
int main(){
    vector<int>arr = {4,2,0,3,2,5};
    int sol = trap(arr);
    cout << sol;
    return 0;
  }