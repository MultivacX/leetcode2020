// 919. Complete Binary Tree Inserter

// Runtime: 36 ms, faster than 26.76% of C++ online submissions for Complete Binary Tree Inserter.
// Memory Usage: 18.8 MB, less than 100.00% of C++ online submissions for Complete Binary Tree Inserter.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : _root(root), _nodes{root}, _index(0) {
        get_1st_completely_filled_level();
    }
    
    int insert(int v) {
        auto node = _nodes[_index];
        if (!node->left) {
            node->left = new TreeNode(v);
        } else {
            node->right = new TreeNode(v);
            ++_index;
            get_1st_completely_filled_level();
        }
        return node->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
    
    void get_1st_completely_filled_level() {
        while (_nodes.back()->right) {
            _index = -1;
            vector<TreeNode*> tmp;
            for (int i = 0; i < _nodes.size(); ++i) {
                if (_nodes[i]->left) {
                    tmp.push_back(_nodes[i]->left);
                    if (_index < 0 && (!_nodes[i]->left->left || !_nodes[i]->left->right)) 
                        _index = tmp.size() - 1;
                }
                
                if (_nodes[i]->right) {
                    tmp.push_back(_nodes[i]->right);
                    if (_index < 0 && (!_nodes[i]->right->left || !_nodes[i]->right->right)) 
                        _index = tmp.size() - 1;
                }
            }
            swap(_nodes, tmp);
        }
    }
    
    TreeNode* _root;
    vector<TreeNode*> _nodes;
    int _index;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */