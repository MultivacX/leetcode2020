// 706. Design HashMap

// Runtime: 116 ms, faster than 90.92% of C++ online submissions for Design HashMap.
// Memory Usage: 40.7 MB, less than 100.00% of C++ online submissions for Design HashMap.

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : v(101, vector<pair<int, int>>()) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket = key % 101;
        auto it = find_if(v[bucket].begin(), v[bucket].end(), [key](pair<int, int>& p) { return p.first == key; });
        if (it == v[bucket].end()) v[bucket].push_back({key, value});
        else it->second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket = key % 101;
        auto it = find_if(v[bucket].begin(), v[bucket].end(), [key](pair<int, int>& p) { return p.first == key; });
        if (it == v[bucket].end()) return -1;
        else return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket = key % 101;
        auto it = find_if(v[bucket].begin(), v[bucket].end(), [key](pair<int, int>& p) { return p.first == key; });
        if (it != v[bucket].end()) {
            swap(*it, v[bucket].back());
            v[bucket].pop_back();
        }
    }
    
    vector<vector<pair<int, int>>> v;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */