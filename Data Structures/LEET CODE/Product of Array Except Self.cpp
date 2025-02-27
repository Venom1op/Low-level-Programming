#include<bits/stdc++.h>
using namespace std;
vector<int>productExceptSelf(vector<int>&nums) {
    int n = nums.size();
    vector<int> result(n,1);
    // compute the left prefix ->
    for (int i = 0 ; i < n ; i++) {
            
    }
    return result;
}
int main(){
    vector<int> nums = {1,2,3,4};
    vector<int>result = productExceptSelf(nums);
    for (int i =0 ; i< result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
  }