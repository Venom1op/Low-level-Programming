#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// functions to rotate and array
void reverse(vector<int> &arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

// functions to rotate an array by k elements
void rotate_array(vector<int> &nums, int k) { 
  int n = nums.size(); 
  // in case k > n
  k = k % n;           

  // step 1 -> reverse the entire array 
  reverse(nums,0 , n-1);
  reverse(nums, 0 , k-1);
  reverse(nums, k, n-1);

}