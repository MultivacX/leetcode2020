// 1530. Number of Good Leaf Nodes Pairs
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// Runtime: 144 ms, faster than 33.74% of C++ online submissions for Number of Good Leaf Nodes Pairs.
// Memory Usage: 32 MB, less than 5.10% of C++ online submissions for Number of Good Leaf Nodes Pairs.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<uint64_t>> leaves;
    
    void getLeaves(TreeNode* node, uint64_t idx, uint64_t level) {
        if (!node) return;
        
        if (!node->left && !node->right) {
            leaves.push_back(vector<uint64_t>{idx, level});
            return;
        }
        
        if (node->left) getLeaves(node->left, 2 * idx, level + 1);
        if (node->right) getLeaves(node->right, 2 * idx + 1, level + 1);
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        getLeaves(root, 1, 1);
        // for (const auto& v : leaves) cout << "id:" << v[0] << ", lv:" << v[1] << endl;
        if (leaves.size() < 2) return 0;
        
        int ans = 0;
        for (int i = 0; i + 1 < leaves.size(); ++i) {
            for (int j = i + 1; j < leaves.size(); ++j) {
                uint64_t id0 = leaves[i][0];
                uint64_t lv0 = leaves[i][1];
                uint64_t id1 = leaves[j][0];
                uint64_t lv1 = leaves[j][1];
                int d = 0;
                // optim when lv0 == lv1
                // cout << endl;
                while (d < distance && id0 != id1) {
                    // printf("%d,%d -- %d,%d\n", id0, lv0, id1, lv1);
                    if (lv0 == lv1) {
                        id0 /= 2;
                        lv0 -= 1;
                        id1 /= 2;
                        lv1 -= 1;
                        d += 2;
                    } else if (lv0 > lv1) {
                        id0 /= 2;
                        lv0 -= 1;
                        d += 1;
                    } else {
                        id1 /= 2;
                        lv1 -= 1;
                        d += 1;
                    }
                }
                // printf("%d,%d -- %d,%d\n", id0, lv0, id1, lv1);
                if (d <= distance && id0 == id1) ++ans;
            }
        }
        return ans;
    }
};