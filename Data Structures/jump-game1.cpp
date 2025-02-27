#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool canJump(vector<int> nums) {
  int goal = nums.size() - 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
  }
  return goal == 0;
}
int main() {
  // driver code
  vector<int> arr = {1, 1, 0, 1, 4};
  bool result = canJump(arr);
  if (result == true) {
    cout << "possible!!\n";
  } else {
    cout << "not possbile\n";
  }
  return 0;
}