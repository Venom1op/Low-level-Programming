#include <bits/stdc++.h>
using namespace  std;
class randomizedset {
private:
    unordered_map<int,int>map;
    vector<int> values;
public:
    // calling constructor
    randomizedset(){};
    bool insert(int val) {
    if (map.find(val)!= map.end()) return false;
     values.push_back(val);
     map[val] = values.size()-1;
        return true;
    }
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            cout << "Element not found\n";
            return false;
        }
        int last_element = values.back();
        int idx = map[val];
        values[idx] = last_element;
        map[last_element] = idx;
        values.pop_back();
        map.erase(val);
        return true;
    }
    int random() {
        int random_index = rand() % values.size();
        return values[random_index];
    }
};

int  main(){
  randomizedset rs;
  cout << rs.insert(1) << endl;  // true
  cout << rs.remove(2) << endl;  // false
  cout << rs.insert(2) << endl;  // true
  cout << rs.random() << endl; // Either 1 or 2
  cout << rs.remove(1) << endl;  // true
  cout << rs.insert(2) << endl;  // false
  cout << rs.random() << endl; // Always 2
  return 0;
  }
