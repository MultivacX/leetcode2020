// 170. Two Sum III - Data structure design
// https://leetcode.com/problems/two-sum-iii-data-structure-design/

// Runtime: 96 ms, faster than 90.98% of C++ online submissions for Two Sum III - Data structure design.
// Memory Usage: 24.5 MB, less than 35.82% of C++ online submissions for Two Sum III - Data structure design.
    
class TwoSum {
    map<int, int> m;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (m.empty()) return false;
        
        auto l = m.begin();
        if (value < l->first * 2) return false;
        
        auto r = m.end(); --r;
        if (value > r->first * 2) return false;
        
        while (l != m.end() && r != m.end()) {
            if (l->first == r->first) {
                return l->second > 1 && value == l->first * 2;
            } else if (l->first > r->first) {
                return false;
            }
            
            int sum = l->first + r->first;
            if (value == sum) return true;
            value > sum ? ++l : --r;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */