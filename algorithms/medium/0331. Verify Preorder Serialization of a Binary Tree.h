// 331. Verify Preorder Serialization of a Binary Tree

// Runtime: 4 ms, faster than 88.17% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.

// Time Complexity: O(N).
// Space Complexity: O(lgN).

class Solution {
public:
    bool isValidSerialization(string preorder) {
        const int N = preorder.length();
        if (N == 0) return true;
        if (preorder[0] == '#') return N == 1;
        
        int i = 0;
        vector<bool> v; // true : left child visited
        bool root = false;
        while (i < N) {
            char val = preorder[i];
            while (i < N && preorder[i] != ',') ++i;
            if (v.empty()) {
                if (val != '#' && !root) v.push_back(false);
                else return false;
                root = true;
            } else if (v.back() == false) {
                // v.back()'s left child
                v.back() = true;
                if (val != '#') v.push_back(false);
            } else {
                // v.back()'s right child
                v.pop_back();
                if (val != '#') v.push_back(false);
            }
            // skip ,
            ++i;
        }
        return v.empty() && i >= N;
    }
};