// 715. Range Module

class RangeModule {
    map<int, bool> m;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        m[left] = true;
        if (!m.count(right)) m[right] = false;
        
        int L = left;
        auto it = m.find(left);
        if (it != m.begin() && (--it)->second) L = it->first;
        
        int R = right;
        it = m.find(right);
        if (it != m.end() && !(++it)->second) R = it->first;
        
        vector<int> useless;
        it = m.find(L); ++it;
        for (; it != m.find(R); ++it) useless.push_back(it->first);
        while (!useless.empty()) {
            m.erase(useless.back());
            useless.pop_back();
        }
    }
    
    bool queryRange(int left, int right) {
        auto it = m.lower_bound(left);
        if (it == m.end()) return false;
        if (it == m.begin() && (it->first != left || !it->second)) return false;
        if (it->first != left && !(--it)->second) return false;
        auto L = it;
        
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
        if (it != m.begin() && it->first != left) --it;
        auto L = it;
        
        auto R = m.lower_bound(right);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */


// ["RangeModule","addRange","queryRange","addRange","queryRange","addRange","removeRange","removeRange","removeRange","queryRange"]
// [[],[5,7],[2,7],[6,9],[2,9],[2,7],[3,10],[1,8],[1,10],[4,7]]
class RangeModule {
    // [left, right)
    map<int, int> m;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        if (m.empty()) {
            m.emplace(left, right);
            return;
        }
        
        // right <= it.left
        auto it = m.lower_bound(right);
        if (it == m.begin()) {
            int L = it->first;
            int R = it->second;
            if (right < L) m.emplace(left, right);
            else emplace(left, right);
            return;
        }
        
        vector<int> removed;
        --it;
        while (true) {
            int L = it->first;
            int R = it->second;
            
            if (R <= left) {
                break;
            } else if (L <= left/* and left < R */) {
                left = L;
                removed.emplace_back(L);
                break;
            } else /* left < L */ {
                removed.emplace_back(L);
            }
            
            if (it == m.begin())
                break;
            --it;
        }
        for (int L : removed) m.erase(L);
        emplace(left, right);
    }
    
    void emplace(int left, int right) {
        printf("[%d, %d) ", left, right); cout << " + ";
        for (auto p : m) printf("[%d, %d) ", p.first, p.second); cout << " -> ";
        auto it = ++m.emplace(left, right).first;
        vector<int> removed;
        while (it != m.end()) {
            int L = it->first;
            int R = it->second;
            if (L <= right) {
                removed.emplace_back(L);
                right = max(right, R);
                m[left] = right;
            } else {
                break;
            }
            ++it;
        }
        for (int L : removed) m.erase(L);
        for (auto p : m) printf("[%d, %d) ", p.first, p.second); cout << endl;
    }
    
    bool queryRange(int left, int right) {
        if (m.empty()) return false;
        
        // right <= it.left
        auto it = m.lower_bound(right);
        if (it == m.begin()) return false;
        
        --it;
        int L = it->first;
        int R = it->second;
        return L <= left && right <= R;
    }
    
    void removeRange(int left, int right) {
        if (m.empty()) return;
        
        // right <= it.left
        auto it = m.lower_bound(right);
        if (it == m.begin()) return;
        
        printf("[%d, %d) ", left, right); cout << " - ";
        for (auto p : m) printf("[%d, %d) ", p.first, p.second); cout << " -> ";
        --it;
        int L = it->first;
        int R = it->second;
        if (L <= left && right <= R) {
            if (L < left) it->second = left;
            else /* L == left */ m.erase(L);
            if (right < R) m.emplace(right, R);
        }
        for (auto p : m) printf("[%d, %d) ", p.first, p.second); cout << endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */