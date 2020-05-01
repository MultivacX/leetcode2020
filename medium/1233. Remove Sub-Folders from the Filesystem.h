// 1233. Remove Sub-Folders from the Filesystem

// Runtime: 408 ms, faster than 30.39% of C++ online submissions for Remove Sub-Folders from the Filesystem.
// Memory Usage: 57.7 MB, less than 100.00% of C++ online submissions for Remove Sub-Folders from the Filesystem.

// Time Complexity: O(sum(length(folder[i]))).
// Space Complexity: O(count(all sub-folders)).

class Solution {
    struct Node {
        string path;
        unordered_map<string, Node*> children;
        
        bool isEnd() { return !path.empty(); }
        
        Node* getChild(const string& name) {
            auto it = children.find(name);
            if (it == children.end()) 
                children[name] = new Node;
            return children[name];
        }
    };
    
    Node root;
    
    void build(const string& f) {
        // cout << f << " -> ";
        Node* node = &root;
        int i = 0;
        while (i < f.length()) {
            // skip '/'
            ++i;
            
            string name;
            while (i < f.length() && f[i] != '/') name += f[i++];
            // cout << name << "--";
            auto n = node->getChild(name);
            if (n->isEnd()) return;
            node = n;
        }
        node->path = f;
        // cout << " ~~~~ " << node->path << endl;
    }
    
    void find(vector<string>& ans, Node* node) {
        if (node->isEnd()) {
            ans.push_back(node->path);
            return;
        }
        
        for (const auto& child : node->children) find(ans, child.second);
    }
    
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for (const string& f : folder) build(f);
        vector<string> ans;
        find(ans, &root);
        return ans;
    }
};