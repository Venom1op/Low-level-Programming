#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums) {
 int jumps = 0 , farthest = 0 , currentend = 0;
 for (int i = 0 ; i < nums.size()-1 ; i++) {
    farthest = max(farthest, i+nums[i]);
    if (i == currentend) {
        jumps++;
        currentend = farthest;
    }
 }
 return jumps;
}
int main() {
  vector<int> arr = {2,3,1,1,4};
  int result = jump(arr);
  cout << result;
  return 0;
}