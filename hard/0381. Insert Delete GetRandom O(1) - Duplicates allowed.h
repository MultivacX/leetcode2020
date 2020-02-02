// 381. Insert Delete GetRandom O(1) - Duplicates allowed

// Runtime: 60 ms, faster than 71.17% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// Memory Usage: 24.6 MB, less than 25.00% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vals.push_back(val);
        mem[val].insert(vals.size() - 1);
        return mem[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mem.find(val) == mem.end())
            return false;
        
        int idx = *(mem[val].begin());
        mem[val].erase(idx);
        if (mem[val].empty())
            mem.erase(val);
        
        if (idx == vals.size() - 1) {
            vals.pop_back();
        } else {
            int last_idx = vals.size() - 1;
            int last_val = vals.back();
            vals[idx] = last_val;
            vals.pop_back();
            
            mem[last_val].erase(last_idx);
            mem[last_val].insert(idx);
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
    
    unordered_map<int, unordered_set<int>> mem;
    vector<int> vals;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */