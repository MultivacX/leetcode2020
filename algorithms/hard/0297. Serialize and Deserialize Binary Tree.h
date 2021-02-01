// 297. Serialize and Deserialize Binary Tree

// Runtime: 588 ms, faster than 5.00% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 154.8 MB, less than 6.90% of C++ online submissions for Serialize and Deserialize Binary Tree.

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
        int idx = -1; 
        int pos = 0;
        buildPreorderData(root, data, idx, idx, pos);
        //cout << data.str() << endl;
        return data.str();
    }

    void buildPreorderData(TreeNode* root, ostringstream& data, int parentIndex, int& idx, int pos) {
        ++idx;
        data << root->val << " " << parentIndex << " " << idx << " " << pos << endl;
        parentIndex = idx;
        if (root->left) buildPreorderData(root->left, data, parentIndex, idx, -1);
        if (root->right) buildPreorderData(root->right, data, parentIndex, idx, 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        unordered_map<int, TreeNode*> nodes;
        
        istringstream s(data);
        string l;
        while (getline(s, l)) {
            istringstream t(l);
            int val, parentIndex, idx, pos;
            t >> val >> parentIndex >> idx >> pos;
            
            auto node = new TreeNode(val);
            nodes.insert({idx, node});
            if (pos < 0) {
                auto p = nodes[parentIndex];
                p->left = node;
            } else if (pos > 0) {
                auto p = nodes[parentIndex];
                p->right = node;
            }
        }
        
        return nodes[0];
    }

	// WRONG: when duplicates exist in the tree.
    /*// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        auto ans(buildPreorderData(root) + "#" + buildInorderData(root));
        cout << ans << endl;
        return ans;
    }
    
    string buildPreorderData(TreeNode* root) {
        auto data(to_string(root->val));
        if (root->left) data += "," + buildPreorderData(root->left);
        if (root->right) data += "," + buildPreorderData(root->right);
        return data;
    }
    
    string buildInorderData(TreeNode* root) {
        string data;
        if (root->left) data = buildInorderData(root->left) + ",";
        data += to_string(root->val);
        if (root->right) data += "," + buildInorderData(root->right);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        auto n = data.find('#');
        auto preorder = split(data.substr(0, n), ',');
        auto inorder = split(data.substr(n + 1), ',');
        cout << "preorder [";
        for (int i : preorder) {
            cout << i << ",";
        }
        cout << "]" << endl;
        cout << "inorder  [";
        for (int i : inorder) {
            cout << i << ",";
        }
        cout << "]" << endl;
        return buildTree(preorder, inorder);
    }
    
    vector<int> split(const string& s, char delimiter) {
		vector<int> tokens;
   		string token;
   		istringstream tokenStream(s);
   		while (getline(tokenStream, token, delimiter)) {
      		tokens.push_back(stoi(token));
   		}
   		return tokens;
	}
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie) {
        if (ps >= pe) return nullptr;
        
        auto root = new TreeNode(preorder[ps]);
        
        int inorderRootIdx = -1;
        for (int i = is; i < ie; ++i) {
            if (inorder[i] == root->val) {
                inorderRootIdx = i;
                break;
            }
        }
        
        int leftNodeCnt = inorderRootIdx - is;
        
        root->left = build(preorder, ps + 1, ps + 1 + leftNodeCnt, inorder, is, inorderRootIdx);
        root->right = build(preorder, ps + 1 + leftNodeCnt, pe, inorder, inorderRootIdx + 1, ie);
        
        return root;
    }*/
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));