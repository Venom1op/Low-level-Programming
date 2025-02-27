#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;
int main() {
  unordered_map<int, int> umap;
  umap[1] = 2;
  umap[2] = 2;
  umap[3] = 4;
  umap.insert({4, 44});
  if (umap.find(7) != umap.end()) { // find searches with key!! not value
    cout << "Found!!\n";
  } else {
    cout << "not found" << endl;
  }
  if (umap.count(7)) { // cout another way to find key if exist !!
    cout << "exist!!" << endl;
  } else {
    cout << "it dosent exit!!" << endl;
  }

  umap.erase(3); // deletes the key!!;
  for (auto i : umap) {
    cout << i.first << " :" << i.second << endl;
  }

  return 0;
}