// 138. Copy List with Random Pointer

// Runtime: 8 ms, faster than 95.75% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 13.4 MB, less than 100.00% of C++ online submissions for Copy List with Random Pointer.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        map<Node*, Node*> m;
        auto node = head;
        while (node) {
            m[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node) {
            m[node]->next = node->next ? m[node->next] : nullptr;
            m[node]->random = node->random ? m[node->random] : nullptr;
            node = node->next;
        }
        return m[head];
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // oldA -> newA -> oldB -> newB -> ...
        auto p = head;
        while (p) {
            auto oldA = p;
            auto oldB = oldA->next;
            
            auto newA = new Node(oldA->val);
            oldA->next = newA;
            newA->next = oldB;
            
            p = oldB;
        }
        
        p = head;
        while (p) {
            auto oldA = p;
            auto newA = oldA->next;
            auto oldB = newA->next;
            
            if (oldA->random) newA->random = oldA->random->next;
            
            p = oldB;
        }
        
        auto ans = head->next;
        p = head;
        while (p) {
            auto oldA = p;
            auto newA = oldA->next;
            auto oldB = newA->next;
            
            oldA->next = oldB;
            newA->next = oldB ? oldB->next : nullptr;
            
            p = oldB;
        }
        return ans;
    }
};