// 588. Design In-Memory File System
// https://leetcode.com/problems/design-in-memory-file-system/

// Runtime: 24 ms, faster than 45.22% of C++ online submissions for Design In-Memory File System.
// Memory Usage: 15.4 MB, less than 88.30% of C++ online submissions for Design In-Memory File System.
    
struct Node {
    Node() {}
    Node(string n) : name(n) {}
    bool isDir = true;
    string name;
    string content;
    map<string, Node*> children;
};

class FileSystem {
    Node root;
    
    Node* split(const string& s) {
        auto node = &root;
   		string name;
   		istringstream nameStream(s);
   		while (getline(nameStream, name, '/')) {
            auto it = node->children.find(name);
            if (it == node->children.end()) {
                auto child = new Node(name);
                node->children.insert({name, child});
                node = child;
            } else {
                node = it->second;
            }
        }
   		return node;
	}
    
public:
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        auto node = split(path);
        if (!node->isDir) return {node->name};
        
        vector<string> ans;
        for (auto it : node->children) 
            ans.push_back(it.second->name);
        return ans;
    }
    
    void mkdir(string path) {
        split(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto node = split(filePath);
        node->isDir = false;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto node = split(filePath);
        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */