#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<int, int>umap;
    int n , key , value;
    cout << "enter the number of elements : " << endl;
    cin >> n;
    cout << "Enter the key value pairs : \n";
    for (int i = 0 ; i < n; i++) {
        cout << "Enter the key and value: " << endl;
        cin >> key >> value;
        umap[key] = value;
    }
    for (auto i : umap) {
        cout << i.first << " : " << i.second << endl;
    }
    return 0;
}