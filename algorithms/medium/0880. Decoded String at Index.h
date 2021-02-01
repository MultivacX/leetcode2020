// 880. Decoded String at Index

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decoded String at Index.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Decoded String at Index.

class Solution {
public:
    struct SNode {
        string s;
        uint64_t count{0};
        uint64_t children_length{0};
        SNode* next{nullptr};
        
        uint64_t unit_length() { return s.length() + children_length; }
        uint64_t length() { return unit_length() * count; }
    };
    
    string decodeAtIndex(string S, int K) {
        SNode* root = new SNode;
        for (int i = 0; i < S.length(); ++i) {
            if (isdigit(S[i])) {
                root->count = (root->count == 0 ? 1 : root->count) * (S[i] - '0');
            } else {
                if (root->count) {
                    SNode* new_root = new SNode;
                    new_root->children_length = root->length();
                    new_root->next = root;
                    root = new_root;
                }
                root->s += S[i];
            }
        }
        return find(root, K - 1);
    }
    
    string find(SNode* root, int K) {
        if (!root) return "";
        if (K > root->unit_length()) K %= root->unit_length();
        // cout << K << endl;
        if (K >= root->children_length) 
            return string(1, root->s[K - root->children_length]);
        return find(root->next, K);
    }
};