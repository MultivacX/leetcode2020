// 715. Range Module
// https://leetcode.com/problems/range-module/

// Runtime: 312 ms, faster than 60.40% of C++ online submissions for Range Module.
// Memory Usage: 72.8 MB, less than 5.86% of C++ online submissions for Range Module.

class RangeModule {
    // {point, start/end}
    map<int, bool> m;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        m[left] = true;
        if (!m.count(right)) m[right] = false;
        
        auto it = m.find(left);
        auto L = it;
        if (it != m.begin() && (--it)->second) --L;
        ++L;
        
        it = m.find(right);
        auto R = it;
        ++it;
        if (it != m.end() && !it->second) ++R;
        
        m.erase(L, R);
        
        // for (auto it : m) 
        //     if (it.second) cout << "[" << it.first << ", ";
        //     else cout << it.first << ")  ";
        // cout << endl;
    }
    
    bool queryRange(int left, int right) {
        // L <= left
        auto L = m.lower_bound(left);
        // not found
        if (L == m.end()) return false;
        // L < left or L is end
        if (L == m.begin() && (L->first != left || !L->second)) return false;
        if (L->first != left && !(--L)->second) return false;
        
        auto R = m.lower_bound(right);
        if (R == m.end()) return false;
        
        // L <= left < right <= R
        
        int end = 0;
        for (auto it = L; it != R; ++it) {
            if (!it->second) ++end;
            if (end > 0) return false;
        }
        return true;
    }
    
    void removeRange(int left, int right) {
        auto it = m.lower_bound(left);
        if (it == m.end()) return;
        if (it != m.begin()) {
            --it;
            if (it->second) {
                m[left] = false;
                it = m.find(left);
            }
            ++it;
        }
        
        auto L = it;
        auto R = m.upper_bound(right);
        bool isRightStart = R != m.end() && !R->second;
        m.erase(L, R);
        if (isRightStart) m[right] = true;
        
        // for (auto it : m) 
        //     if (it.second) cout << "[" << it.first << ", ";
        //     else cout << it.first << ")  ";
        // cout << endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
