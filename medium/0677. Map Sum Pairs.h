// 677. Map Sum Pairs

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Map Sum Pairs.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Map Sum Pairs.

class MapSum {
    unordered_map<string, int> pairs;
    
    struct Trie {
        Trie(char _c = 0) : c(_c) {}
        
        char c;
        unordered_map<char, Trie*> children;
        unordered_set<string> keys;
        
        Trie* update_child(char child_key, const string& key) {
            auto child = find_child(child_key);
            if (!child) {
                child = new Trie(child_key);
                children[child_key] = child;
            }
            child->keys.insert(key);
            return child;
        }
        
        Trie* find_child(char child_key) {
            auto it = children.find(child_key);
            return it == children.end() ? nullptr : it->second;
        }
        
        int sum(unordered_map<string, int>& pairs) {
            int ans = 0;
            for (auto key : keys)
                ans += pairs[key];
            return ans;
        }
    };
    
    Trie root;
    
    void build(const string& key, int i, Trie* node) {
        if (i >= key.length()) return;
        build(key, i + 1, node->update_child(key[i], key));
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        pairs[key] = val;
        build(key, 0, &root);
    }
    
    int sum(string prefix) {
        int ans = 0;
        Trie* node = &root;
        for (int i = 0; i < prefix.length(); ++i) {
            node = node->find_child(prefix[i]);
            if (!node) break;
            if (i + 1 == prefix.length()) ans = node->sum(pairs);
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
