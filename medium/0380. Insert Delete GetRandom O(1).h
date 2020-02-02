// 380. Insert Delete GetRandom O(1)

// WRONG
// 17 / 18 test cases passed.
/*
class RandomizedSet {
public:
    // Initialize your data structure here. 
    RandomizedSet() {
        std::random_device rd;
        gen = std::default_random_engine(rd());
    }
    
    // Inserts a value to the set. Returns true if the set did not already contain the specified element. 
    bool insert(int val) {
        if (mem.count(val)) 
            return false;
        
        mem.insert({val, len});
        if (len == vals.size())
            vals.push_back(val);
        else
            vals[len] = val;
        ++len;
        
        return true;
    }
    
    // Removes a value from the set. Returns true if the set contained the specified element. 
    bool remove(int val) {
        if (!mem.count(val)) 
            return false;
        
        int idx = mem[val];
        mem.erase(val);
        vals[idx] = vals[len - 1];
        --len;
        if (len) 
            mem[vals[idx]] = idx;
        
        return true;
    }
    
    // Get a random element from the set.
    int getRandom() {
        std::uniform_int_distribution<int> dis(0, len - 1);
        return vals[dis(gen)];
    }
    
    unordered_map<int, int> mem;
    vector<int> vals;
    int len{0};
    
    std::default_random_engine gen;
};
*/
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */