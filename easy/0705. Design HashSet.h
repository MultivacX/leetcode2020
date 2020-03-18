// 705. Design HashSet

// Runtime: 96 ms, faster than 88.06% of C++ online submissions for Design HashSet.
// Memory Usage: 35.2 MB, less than 100.00% of C++ online submissions for Design HashSet.

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : v(101, vector<int>()) {
        
    }
    
    void add(int key) {
        int bucket = key % 101;
        auto it = find(v[bucket].begin(), v[bucket].end(), key);
        if (it == v[bucket].end())
            v[bucket].push_back(key);
    }
    
    void remove(int key) {
        int bucket = key % 101;
        auto it = find(v[bucket].begin(), v[bucket].end(), key);
        if (it != v[bucket].end()) {
            swap(*it, v[bucket].back());
            v[bucket].pop_back();
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucket = key % 101;
        auto it = find(v[bucket].begin(), v[bucket].end(), key);
        return it != v[bucket].end();
    }
    
    vector<vector<int>> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */