#include <bits/stdc++.h>
#include <vector>
using namespace std;
int maxprofit(vector<int> &prices) {
    int profit = 0;
    for (int i = 0 ; i < prices.size()-1 ; i++) {
        if (prices[i] < prices[i+1]) {
            profit = profit + (prices[i+1] - prices[i]);
        }
    }
    return profit;
}
int main() {
    vector<int>arr = {7,1,5,3,6,4};
    int result = maxprofit(arr);
    cout << result;
    return 0;
}