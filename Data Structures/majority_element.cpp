#include<bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
int majority_element(vector<int>&arr){
    unordered_map<int,int> umap;
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        umap[arr[i]]++; 
        if (umap[arr[i]] > arr.size() /2) {
            return arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {1,1,3,2,3,3,3,3};
    int result = majority_element(arr);
    cout << result;
}