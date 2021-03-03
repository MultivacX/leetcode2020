// 642. Design Search Autocomplete System
// https://leetcode.com/problems/design-search-autocomplete-system/

// Runtime: 316 ms, faster than 91.40% of C++ online submissions for Design Search Autocomplete System.
// Memory Usage: 227.1 MB, less than 78.58% of C++ online submissions for Design Search Autocomplete System.
    
class AutocompleteSystem {
    struct Trie {
        vector<int> top3;
        unordered_map<char, Trie*> children;    
    };
    
    vector<string>& sentences_;
    vector<int>& times_;
    unordered_map<string, int> m; // {sentence, k}
    Trie root;
    string prefix;
    Trie* prefixNode = nullptr;
    
    void build(int k, int i, Trie* node) {
        if (i >= sentences_[k].length()) return;
        
        char c = sentences_[k][i];
        if (node->children.count(c) == 0)
            node->children.insert({c, new Trie});
        node = node->children[c];
        if (std::find(begin(node->top3), end(node->top3), k) == end(node->top3))
            node->top3.push_back(k);
        sort(begin(node->top3), end(node->top3), [this](int l, int r){
            return times_[l] > times_[r] || (times_[l] == times_[r] && sentences_[l] < sentences_[r]);
        });
        while (node->top3.size() > 3) 
            node->top3.pop_back();
        build(k, i + 1, node);
    }
    
    vector<string> find(char c) {
        if (c == '#') {
            if (m.count(prefix) == 0) {
                m.insert({prefix, sentences_.size()});
                sentences_.push_back(prefix);
                times_.push_back(0);
            }
            ++times_[m[prefix]];
            build(m[prefix], 0, &root);
                
            prefix = "";
            prefixNode = &root;
            return {};
        }
        
        prefix += c;
        
        if (!prefixNode || prefixNode->children.count(c) == 0) {
            prefixNode = nullptr;
            return {};
        }
        
        prefixNode = prefixNode->children[c];
        vector<string> ans;
        for (int i : prefixNode->top3)
            ans.push_back(sentences_[i]);
        return ans;
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    : sentences_(sentences)
    , times_(times) {
        for (int i = 0; i < sentences_.size(); ++i) {
            build(i, 0, &root);
            m.insert({sentences_[i], i});
        }
        prefixNode = &root;
    }
    
    vector<string> input(char c) {
        return find(c);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */