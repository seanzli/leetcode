#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> hash;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        hash[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end())
            return "";
        
        vector<pair<int, string>> &vec = hash[key];
        auto itr = upper_bound(vec.begin(), vec.end(), make_pair(timestamp, string({127})));
        if (itr == vec.begin())
            return "";
        return (itr - 1)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */