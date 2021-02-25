// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Runtime: 36 ms, faster than 98.37% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 30.6 MB, less than 88.60% of C++ online submissions for Serialize and Deserialize Binary Tree.
    
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
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front();
                q.pop();
                data << node->val << ' ';
                data << (node->left ? 1 : 0) << ' ';
                data << (node->right ? 1 : 0);
                if (size > 0) data << ' ';
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            data << '\n';
        }
        cout << data.str() << endl;
        return data.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        TreeNode* root = nullptr;
        vector<tuple<TreeNode*, int, int>> nodes;
        istringstream s(data);
        string line;
        while (getline(s, line, '\n')) {
            vector<tuple<TreeNode*, int, int>> tmp;
            istringstream t(line);
            while (!t.eof()) {
                int val, left, right; t >> val >> left >> right;
                tmp.push_back({new TreeNode(val), left, right});
            }
            cout << tmp.size() << endl;
            if (!root) {
                root = get<0>(tmp[0]);
            } else {
                for (int i = 0, j = 0; i < nodes.size(); ++i) {
                    if (get<1>(nodes[i]) && j < tmp.size()) get<0>(nodes[i])->left = get<0>(tmp[j++]);
                    if (get<2>(nodes[i]) && j < tmp.size()) get<0>(nodes[i])->right = get<0>(tmp[j++]);
                }
            }
            nodes = tmp;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


// Runtime: 588 ms, faster than 5.00% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 154.8 MB, less than 6.90% of C++ online submissions for Serialize and Deserialize Binary Tree.

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


// TLE
/*class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        ostringstream data;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = 0;
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front();
                q.pop();
                int val = node ? node->val : 1001;
                data << val << ' ';
                q.push(node ? node->left : nullptr);
                q.push(node ? node->right : nullptr);
                if (node && (node->left || node->right)) ++n;
            }
            if (n == 0) break;
        }
        return data.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        vector<TreeNode*> nodes;
        istringstream s(data);
        int i = 0;
        while (!s.eof()) {
            int val; s >> val;
            nodes.push_back(val != 1001 ? new TreeNode(val) : nullptr);
            while (i * 2 + 2 < nodes.size()) {
                if (nodes[i]) {
                    nodes[i]->left = nodes[i * 2 + 1];
                    nodes[i]->right = nodes[i * 2 + 2];
                }
                ++i;
            }
        }
        return nodes[0];
    }
};*/