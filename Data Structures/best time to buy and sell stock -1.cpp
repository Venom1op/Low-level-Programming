#include <bits/stdc++.h>
#include <climits>
int maxprofit(std::vector<int> &prices) {
  int max_profit = 0;
  int min_price = INT_MAX;
  for (int price : prices) {
    min_price = std::min(min_price, price);
    max_profit = std::max(max_profit, price - min_price);
  }
  return max_profit;
}
int main(){
  std::vector<int> arr = {17,1,5,3,6,4};
  int result = maxprofit(arr);
  std::cout << result;
  return 0;
}