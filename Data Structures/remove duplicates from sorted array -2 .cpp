#include<bits/stdc++.h>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>&arr){
    unordered_set<int> uset;
    int index = 0;
    for (int element  :arr ) {
        if (uset.find(element) == uset.end()) {
            arr[index++] = element;
            uset.insert(element);
        }
    }
    return index;
}
int main(){
    vector<int> arr = {1,1,1,2,2,3};
    int index = removeDuplicates(arr);
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}