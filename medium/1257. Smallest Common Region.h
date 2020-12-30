// 1257. Smallest Common Region
// https://leetcode.com/problems/smallest-common-region/

// Runtime: 168 ms, faster than 39.80% of C++ online submissions for Smallest Common Region.
// Memory Usage: 57.2 MB, less than 5.10% of C++ online submissions for Smallest Common Region.
    
class Solution {
    struct Node {
        Node() {}
        Node(const string& n) : name(n) {}
        Node* parent = nullptr;
        string name;
        unordered_map<string, Node*> children;
    };
    
    unordered_map<string, Node*> nodes;
    
    Node* getNode(const string& n, Node* parent = nullptr) {
        Node* node = nullptr;
        if (nodes.count(n) == 0) {
            node = new Node(n);
            nodes.insert({n, node});
        } else {
            node = nodes[n];
        }
        if (parent) node->parent = parent;
        return node;
    }
    
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        for (const auto& v : regions) {
            auto node = getNode(v[0]);
            for (int i = 1; i < v.size(); ++i) 
                node->children[v[i]] = getNode(v[i], node);
        }
        unordered_set<string> s;
        auto n1 = nodes[region1];
        auto n2 = nodes[region2];
        while (n1 || n2) {
            if (n1) {
                if (!s.insert(n1->name).second)
                    return n1->name;
                n1 = n1->parent;
            }
            if (n2) {
                if (!s.insert(n2->name).second)
                    return n2->name;
                n2 = n2->parent;
            }
        }
        return "";
    }
};