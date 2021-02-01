// 432. All O`one Data Structure

// Runtime: 112 ms, faster than 9.49% of C++ online submissions for All O`one Data Structure.
// Memory Usage: 28.3 MB, less than 11.11% of C++ online submissions for All O`one Data Structure.

// Time Complexity: O(1).
// Space Complexity: O(count(keys)).

class AllOne {
    using Data = pair<int, unordered_set<string>>;
    using Iterator = list<Data>::iterator;
    
    // {count, keys}
    list<Data> l;
    
    // {key, count}
    unordered_map<string, int> m0;
    
    // {count, list<Data>::iterator}
    unordered_map<int, Iterator> m1;
    
    void print() {
        for (auto it : l) {
            cout << it.first << ": ";
            for (const string& key : it.second) cout << key << ", ";
            cout << endl;
        }
        cout << endl;
    }
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (m0.count(key) == 0) {
            const int new_count = 1;
            m0.emplace(key, new_count);
            
            if (m1.count(new_count) == 0) {
                l.emplace_front(Data{new_count, {key}});
                m1.emplace(new_count, l.begin());
            } else {
                m1[new_count]->second.emplace(key);
            }
        } else {
            const int old_count = m0[key];
            ++m0[key];
            const int new_count = old_count + 1;
            
            auto old_it = m1[old_count];
            if (m1.count(new_count) == 0) {
                auto new_it = ++old_it;
                new_it = l.emplace(new_it, Data{new_count, {key}});
                m1.emplace(new_count, new_it);
            } else {
                m1[new_count]->second.emplace(key);
            }
            
            old_it = m1[old_count];
            old_it->second.erase(key);
            if (old_it->second.empty()) {
                m1.erase(old_count);
                l.erase(old_it);
            }
        }
        // print();
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m0.count(key) == 0) return;
        
        const int old_count = m0[key];
        --m0[key];
        const int new_count = old_count - 1;
        
        auto old_it = m1[old_count];
        if (new_count != 0) {
            if (m1.count(new_count) == 0) {
                auto new_it = l.emplace(old_it, Data{new_count, {key}});
                m1.emplace(new_count, new_it);
            } else {
                m1[new_count]->second.emplace(key);
            }
        } else {
            m0.erase(key);
        }
        
        old_it = m1[old_count];
        old_it->second.erase(key);
        if (old_it->second.empty()) {
            m1.erase(old_count);
            l.erase(old_it);
        }
        // print();
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l.empty() ? "" : *(l.back().second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return l.empty() ? "" : *(l.front().second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */