// 1483. Kth Ancestor of a Tree Node
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

// Runtime: 260 ms, faster than 97.41% of C++ online submissions for Kth Ancestor of a Tree Node.
// Memory Usage: 110.9 MB, less than 81.84% of C++ online submissions for Kth Ancestor of a Tree Node.
    
class TreeAncestor {
    vector<vector<int>> ancestors;
    
public:
    TreeAncestor(int n, vector<int>& parent) : ancestors(20, vector<int>(n, -1)) {
        ancestors[0] = parent;
        for (int j = 1; j < 20; ++j) {
            const auto& children = ancestors[j - 1];
            auto& cur = ancestors[j];
            for (int i = 0; i < n; ++i) 
                cur[i] = children[i] >= 0 ? children[children[i]] : -1;
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 19; i >= 0 && node >= 0 && k > 0; --i) {
            int cnt = 1 << i;
            while (node >= 0 && k >= cnt) {
                node = ancestors[i][node];
                k -= cnt;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


// Runtime: 944 ms, faster than 5.19% of C++ online submissions for Kth Ancestor of a Tree Node.
// Memory Usage: 102.7 MB, less than 95.10% of C++ online submissions for Kth Ancestor of a Tree Node.
    
class TreeAncestor {
    vector<int> l1;
    vector<int> l2;
    vector<int> l4;
    vector<int> l8;
    vector<int> l16;
    
public:
    TreeAncestor(int n, vector<int>& parent) : l1(parent), l2(n), l4(n), l8(n), l16(n) {
        for (int i = 0; i < n; ++i) 
            l2[i] = l1[i] >= 0 ? l1[l1[i]] : -1;
        for (int i = 0; i < n; ++i) 
            l4[i] = l2[i] >= 0 ? l2[l2[i]] : -1;
        for (int i = 0; i < n; ++i) 
            l8[i] = l4[i] >= 0 ? l4[l4[i]] : -1;
        for (int i = 0; i < n; ++i) 
            l16[i] = l8[i] >= 0 ? l8[l8[i]] : -1;
    }
    
    int getKthAncestor(int node, int k) {
        while (node >= 0 && k >= 16) {
            node = l16[node];
            k -= 16;
        }
        while (node >= 0 && k >= 8) {
            node = l8[node];
            k -= 8;
        }
        while (node >= 0 && k >= 4) {
            node = l4[node];
            k -= 4;
        }
        while (node >= 0 && k >= 2) {
            node = l2[node];
            k -= 2;
        }
        while (node >= 0 && k >= 1) {
            node = l1[node];
            k -= 1;
        }
        return node;
    }
};