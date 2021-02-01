// 1361. Validate Binary Tree Nodes

// Runtime: 52 ms, faster than 74.40% of C++ online submissions for Validate Binary Tree Nodes.
// Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Validate Binary Tree Nodes.

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // parent_count[root] = 0;
        // parent_count[non_root] = 1;
        vector<int> parent_count(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (parent_count[leftChild[i]] > 0 || leftChild[i] == i)
                    return false;
                ++parent_count[leftChild[i]];
            }
            
            if (rightChild[i] != -1) {
                if (parent_count[rightChild[i]] > 0 || rightChild[i] == i)
                    return false;
                ++parent_count[rightChild[i]];
            }
        }
        
        int root_index = -1;
        for (int i = 0; i < n; ++i) {
            if (parent_count[i] == 0) {
                if (root_index != -1)
                    return false;
                root_index = i;
            }
        }
        if (n == 1) return root_index != -1 && leftChild[root_index] == -1 && rightChild[root_index] == -1;
        return root_index != -1 && (leftChild[root_index] != -1 || rightChild[root_index] != -1);
    }
};