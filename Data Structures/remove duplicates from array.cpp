#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int removeDuplicates(vector<int>&arr){
  unordered_set<int> umap;
  int index = 0;
  for (int element : arr) {
      if (umap.find(element) == umap.end()) {
          arr[index++] = element;
          umap.insert(element);
      }
  }
}   
int main() {
    vector<int> arr = {1,2,2,3,3};
  int index =   removeDuplicates(arr);
    for (int i = 0 ; i < index; i++) {
        printf("%d\n", arr[i]);
    }
return 0;
}