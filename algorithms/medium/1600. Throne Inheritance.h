// 1600. Throne Inheritance
// https://leetcode.com/problems/throne-inheritance/

// Runtime: 632 ms, faster than 92.71% of C++ online submissions for Throne Inheritance.
// Memory Usage: 169.9 MB, less than 56.32% of C++ online submissions for Throne Inheritance.
    
class ThroneInheritance {
    class Node {
    public:
        Node(const string& n, Node* p)
        : name(n)
        , parent(p)
        , alive(true) {
        }

        string name;
        Node* parent;
        bool alive;
        vector<Node*> children;
    };

    Node* root;
    unordered_map<string, Node*> m;
    
    void getOrder(vector<string>& order, Node* node) {
        if (node->alive) order.push_back(node->name);
        for (auto c : node->children) getOrder(order, c);
    }
    
public:
    ThroneInheritance(string kingName) {
        root = new Node(kingName, nullptr);
        m.insert({kingName, root});
    }
    
    void birth(string parentName, string childName) {
        auto p = m[parentName];
        auto c = new Node(childName, p);
        p->children.push_back(c);
        m.insert({childName, c});
    }
    
    void death(string name) {
        m[name]->alive = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        getOrder(order, root);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */