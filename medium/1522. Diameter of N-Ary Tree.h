// 1522. Diameter of N-Ary Tree
// https://leetcode.com/problems/diameter-of-n-ary-tree/

// Runtime: 28 ms, faster than 95.50% of C++ online submissions for Diameter of N-Ary Tree.
// Memory Usage: 11.2 MB, less than 49.55% of C++ online submissions for Diameter of N-Ary Tree.
    
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int ans = 0;
    
    int helper(Node* root) {
        if (!root) return 0;
        
        int a = 0, b = 0;
        for (auto c : root->children) {
            int l = helper(c);
            if (a < l) {
                if (b < a) b = a;
                a = l;
            } else if (b < l) b = l;
        }
        // cout << root->val << ": " << a << ", " << b << endl;
        ans = max(ans, a + b);
        return a + 1;
    }
    
public:
    int diameter(Node* root) {
        helper(root);
        return ans;
    }
};