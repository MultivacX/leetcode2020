// 380. Insert Delete GetRandom O(1)

// Runtime: 56 ms, faster than 69.72% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 22.3 MB, less than 76.92% of C++ online submissions for Insert Delete GetRandom O(1).

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mem.count(val)) 
            return false;
        
        mem.insert({val, vals.size()});
        vals.push_back(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mem.count(val)) 
            return false;

        int idx = mem[val];
        mem.erase(val);
        
        int last_val = vals.back(); 
        vals[idx] = last_val;
        if (idx == vals.size() - 1) {
            vals.pop_back();
        } else {
            vals.pop_back();
            mem[last_val] = idx;
        }
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
    
    unordered_map<int, int> mem;
    vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> m; // {val, idx}
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val)) return false;
        m.insert({val, vals.size()});
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;
        
        int i = m[val];
        m.erase(val);
        
        int j = vals.size() - 1;
        if (i != j) {
            vals[i] = vals[j];
            m[vals[i]] = i;
        }
        vals.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};