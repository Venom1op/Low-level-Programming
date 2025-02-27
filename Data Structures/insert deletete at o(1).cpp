#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
class randomizedset {
private:
  unordered_map<int, int> mp; // stores value -> index maping
  vector<int> value;          // stores the actual value

public:
  randomizedset() {}

  bool insert(int val) {
    if (mp.find(val) != mp.end())
      return false;
    value.push_back(val);
    mp[val] = value.size() - 1;
    
    return true;
  }
  bool remove(int val){
    if (mp.find(val) == mp.end()) {
        return false; // return not found
    }
    int last_element = value.back();
  }
}