// 449. Serialize and Deserialize BST

// Runtime: 36 ms, faster than 84.90% of C++ online submissions for Serialize and Deserialize BST.
// Memory Usage: 28.5 MB, less than 15.38% of C++ online submissions for Serialize and Deserialize BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        ostringstream data;
        serialize(root, data);
        // cout << data.str() << endl;
        return data.str();
    }
    
    void serialize(TreeNode* root, ostringstream& data) {
        data << root->val;
        if (root->left) {
            data << ' ';
            serialize(root->left, data);
        }
        if (root->right) {
            data << ' ';
            serialize(root->right, data);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        vector<int> vals;
        istringstream s(data);
        while (!s.eof()) {
            int val; s >> val;
            vals.push_back(val);
            // cout << val << endl;
        }
        return deserialize(vals, 0, vals.size());
    }
    
    TreeNode* deserialize(vector<int>& vals, int begin, int end) {
        if (begin >= end) return nullptr;
        
        auto root = new TreeNode(vals[begin]);
        // printf("[%d, %d)\n", begin, end);
        for (int i = begin + 1; i < end; ++i) {
            if (vals[i] > vals[begin]) {
                // printf("  L[%d, %d)\n", begin + 1, i);
                // printf("  R[%d, %d)\n", i, end);
                // [begin + 1, i)
                root->left = deserialize(vals, begin + 1, i);
                // [i, end)
                root->right = deserialize(vals, i, end);
                break;
            } else if (i == end - 1) {
                // printf("  L[%d, %d)\n", begin + 1, end);
                // [begin + 1, i)
                root->left = deserialize(vals, begin + 1, end);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));