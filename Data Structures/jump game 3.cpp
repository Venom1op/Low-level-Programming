#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
bool canReach(vector<int> nums, int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) 
  {
    int i = q.front();
    q.pop();
    if (nums[i] == 0) {
        return true;
    }
    if (nums[i] < 0) {
        continue;
    }
    if (i + nums[i] < nums.size()) {
        q.push(i+nums[i]);
    }
    if (i - nums[i] >= 0) {
        q.push(i-nums[i]);
    }
    nums[i] = -nums[i];
  }
  return false;
}
int main() {
    vector<int>arr = {4,2,3,0,3,1,2};
    bool result = canReach(arr, 5);
    if (result == true) {
        cout << "possible!!";
    }
    else{
        cout << "not possible!!";
    }
    return 0;
}