// 421. Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/

// Runtime: 204 ms, faster than 28.77% of C++ online submissions for Maximum XOR of Two Numbers in an Array.
// Memory Usage: 43.8 MB, less than 22.97% of C++ online submissions for Maximum XOR of Two Numbers in an Array.

class Solution {
    class Trie {
    public:
        vector<Trie*> nodes{nullptr, nullptr};
    };
    
    Trie root;
    
    void build(Trie* node, int num, int position) {
        if (position < 0) return;
        if (num & (1 << position)) {
            if (!node->nodes[1]) node->nodes[1] = new Trie;
            build(node->nodes[1], num, position - 1);
        } else {
            if (!node->nodes[0]) node->nodes[0] = new Trie;
            build(node->nodes[0], num, position - 1);
        }
    }
    
    void find(Trie* node, int num, int position, int& val) {
        if (position < 0) return;
        if (num & (1 << position)) {
            if (node->nodes[0]) {
                val |= 1 << position;
                find(node->nodes[0], num, position - 1, val);
            } else {
                find(node->nodes[1], num, position - 1, val);
            }
        } else {
            if (node->nodes[1]) {
                val |= 1 << position;
                find(node->nodes[1], num, position - 1, val);
            } else {
                find(node->nodes[0], num, position - 1, val);
            }
        }
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)
            build(&root, num, 31);
        int ans = 0;
        for (int num : nums) {
            int val = 0;
            find(&root, num, 31, val);
            ans = max(ans, val);
        }
        return ans;
    }
};