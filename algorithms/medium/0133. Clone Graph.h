// 133. Clone Graph

// Runtime: 16 ms, faster than 99.39% of C++ online submissions for Clone Graph.
// Memory Usage: 16.7 MB, less than 83.33% of C++ online submissions for Clone Graph.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        clone(node);
        return m[node];
    }
    
    unordered_map<Node*, Node*> m;
    void clone(Node* node) {
        if (!node || m.count(node)) return;
        
        auto new_node = new Node();
        new_node->val = node->val;
        m.insert({node, new_node});
        
        for (auto n : node->neighbors) {
            clone(n);
        }
        
        for (auto n : node->neighbors) {
            new_node->neighbors.push_back(m[n]);
        }
    }
};