#include <bits/stdc++.h>
using namespace std;
vector<int> productitself(vector<int>&nums) {
    int n = nums.size();
    vector<int> result(n,1);
    int leftproduct = 1;
    for (int i = 0 ; i < n ; i++) {
        result[i] = leftproduct;
        leftproduct *= nums[i];
    }
    int rightproduct = 1;
    for (int i = n -1 ; i >= 0; i--) {
        result[i] *= rightproduct;
        rightproduct *= nums[i];
    }
    return result;
}

int main() {

}
