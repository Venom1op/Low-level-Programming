#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  vector<int> arr = {1, 1, 2, 1, 3};
  unordered_map<int, int> umap;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    umap[arr[i]]++;
  }
  cout << "Frequencies of elements:\n";
  for (auto &element : umap) {
    cout << element.first << " -> " << element.second << endl;
  }
  return 0;
}