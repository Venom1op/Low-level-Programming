<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
       int profit = 0;
       for(int i = 1; i < prices.size(); i++) {
         if(prices[i] > prices[i-1]) {
           profit += prices[i] - prices[i-1];
         }
       }
       return profit;
}
int main() {
  vector<int> prices = {7,1,5,3,6,4};
  int profit = maxProfit(prices);
  cout<<profit<<endl;
=======
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
       int profit = 0;
       for(int i = 1; i < prices.size(); i++) {
         if(prices[i] > prices[i-1]) {
           profit += prices[i] - prices[i-1];
         }
       }
       return profit;
}
int main() {
  vector<int> prices = {7,1,5,3,6,4};
  int profit = maxProfit(prices);
  cout<<profit<<endl;
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}