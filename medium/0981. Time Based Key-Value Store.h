// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

// Runtime: 684 ms, faster than 80.19% of C++ online submissions for Time Based Key-Value Store.
// Memory Usage: 130.7 MB, less than 24.43% of C++ online submissions for Time Based Key-Value Store.

class TimeMap {
    // {key, {-ts, val}}
    unordered_map<string, map<int, string>> m;
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (m.count(key) == 0) return "";
        auto it = m[key].lower_bound(-timestamp);
        if (it == m[key].end()) return "";
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */