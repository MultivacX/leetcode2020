// 1166. Design File System
// https://leetcode.com/problems/design-file-system/

// Runtime: 252 ms, faster than 71.51% of C++ online submissions for Design File System.
// Memory Usage: 66.5 MB, less than 93.01% of C++ online submissions for Design File System.
    
class Node {
public:
    string name;
    int val;
    unordered_map<string, Node*> children;
};

class FileSystem {
    Node root;
    
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        const int N = path.length();
        if (N <= 1 || path[0] != '/' || !isalpha(path.back())) return false;
        Node* parent = &root;
        string name;
        for (int i = 1, j = 1; j < N; ++j) {
            if (path[j] != '/') name += path[j];
            
            if (path[j] == '/') {
                // its parent path doesn't exist
                if (parent->children.count(name) == 0)
                    return false;
                parent = parent->children[name];
                name.clear();    
            } else if (j + 1 == N) {
                // the path already exists
                if (parent->children.count(name))
                    return false;
                Node* node = new Node;
                node->name = name;
                node->val = value;
                parent->children.insert({name, node});
            }
        }
        return true;
    }
    
    int get(string path) {
        const int N = path.length();
        if (N <= 1 || path[0] != '/' || !isalpha(path.back())) return -1;
        Node* parent = &root;
        string name;
        for (int i = 1, j = 1; j < N; ++j) {
            if (path[j] != '/') name += path[j];
            
            if (path[j] == '/') {
                // its parent path doesn't exist
                if (parent->children.count(name) == 0)
                    return -1;
                parent = parent->children[name];
                name.clear();    
            } else if (j + 1 == N) {
                // the path already exists
                if (parent->children.count(name) == 0)
                    return -1;
                return parent->children[name]->val;
            }
        }
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */