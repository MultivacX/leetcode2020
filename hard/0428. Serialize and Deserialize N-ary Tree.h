// 428. Serialize and Deserialize N-ary Tree
// https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

// Runtime: 56 ms, faster than 78.56% of C++ online submissions for Serialize and Deserialize N-ary Tree.
// Memory Usage: 173.4 MB, less than 64.17% of C++ online submissions for Serialize and Deserialize N-ary Tree.
    
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
    int getnum(const string& s, int& i) {
        int num = 0;
        while (i < s.length() && isdigit(s[i]))
            num = num * 10 + s[i++] - '0';
        return num;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        
        Node L, R;
        
        string s;
        deque<Node*> q; 
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto node = q.front(); q.pop_front();
                if (node == &L) s += '[';
                else if (node == &R) s.back() = ']';
                else if (node) {
                    s += to_string(node->val);
                    if (size > 0) s += ',';
                                   
                    if (node->children.empty()) q.push_back(nullptr);
                    else {
                        q.push_back(&L);
                        for (auto c : node->children) q.push_back(c);
                        q.push_back(&R);
                    }
                } else if (size > 0) {
                    s += "*,";
                }
            }
            while (!q.empty() && !q.back()) q.pop_back();
            s += '\n';
        }
        cout << s << endl;
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream f(data);
        Node* root = nullptr;
        queue<Node*> q;
        string line;
        while (getline(f, line)) {
            int i = 0;
            if (!root) {
                root = new Node(getnum(line, i));
                q.push(root);
            } else {
                int size = q.size();
                while (i < line.length()) {
                    auto parent = q.front();
                    if (line[i] == '*' || line[i] == ']') { 
                        ++i;
                        --size;
                        q.pop();
                    } else if (isdigit(line[i])) {
                        auto node = new Node(getnum(line, i));
                        parent->children.push_back(node);
                        q.push(node);
                    } else {
                        ++i;
                    }                   
                }
                while (size-- > 0) q.pop();
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));