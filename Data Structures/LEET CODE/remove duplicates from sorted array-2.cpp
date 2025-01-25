#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> umap;
           for(int i = 0 ; i < nums.size(); i++){
            if(umap[nums[i]] == 2)
                continue;
            umap[nums[i]]++;
           }
           int result = umap.size();
           return result;
    }