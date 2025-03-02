#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>&ratings) {
    // 122 -> 1 2 1 -> 4
    int n = ratings.size();
    vector<int>candies(n,1);
    // left to right pass
    for (int i = 1 ; i < n-1 ;i++)
        {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
    // right to left pass
    for (int i = n-2; i >=0 ;i--)
    {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i] , candies[i+1]+1);
            }
    }
    int res = accumulate(candies.begin(),candies.end(),0);
    return res;
}
int main() {
    vector<int>arr = {1,2,2};
    int sol = candy(arr);
    cout << sol << " " << "new sol";
    return 0;
}