#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
int h_index(vector<int> &citations) {
  sort(citations.begin(), citations.end(), greater<int>());
  int count = 0;
  for (int i = 0; i < citations.size(); i++) {
    if (citations[i] > i) {
      count++;
    }
  }
  return count;
}
int main() {
  vector<int> arr = {6,5,3,1,0};
  // 3 1 1
  int result = h_index(arr);
  cout << result ;
}