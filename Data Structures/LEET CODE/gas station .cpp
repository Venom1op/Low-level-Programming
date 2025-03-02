#include<bits/stdc++.h>
using namespace  std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas = accumulate(gas.begin(),gas.end(),0);
    int total_cost = accumulate(cost.begin(),cost.end(),0);
    if (total_cost > total_gas) {
        return -1;
        // solution not possible
    }
    int gas_tank = 0, start_index = 0;
    for (int i = 0 ; i < gas.size(); i++) {
        gas_tank = gas_tank + (gas[i] - cost[i]);
        if (gas_tank < 0) {
            start_index = i + 1;
            gas_tank = 0;
        }
    }
    return start_index;
}
int main() {

}