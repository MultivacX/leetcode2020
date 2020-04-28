// the 30-Day LeetCoding Challenge for the month of April
// April 28th, 2020

// First Unique Number

// Runtime: 468 ms
// Memory Usage: 81.3 MB

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) : idx(0), v(nums) {
        for (int num : nums) ++m[num];
    }
    
    int showFirstUnique() {
        while (idx < v.size() && m[v[idx]] > 1) ++idx;
        if (idx >= v.size()) return -1;
        return v[idx];
    }
    
    void add(int value) {
        v.push_back(value);
        ++m[value];
    }
    
    int idx;
    vector<int> v;
    unordered_map<int, int> m;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */