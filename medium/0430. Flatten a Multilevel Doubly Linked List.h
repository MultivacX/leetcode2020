// 430. Flatten a Multilevel Doubly Linked List

// Runtime: 4 ms, faster than 86.72% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        auto p = head;
        
        while (p) {
            if (p->child) {
                auto old_next = flatten(p->next);
                
                auto new_next = flatten(p->child);
                p->child = nullptr;
                p->next = new_next;
                new_next->prev = p;
                
                while (p->next) p = p->next;
                p->next = old_next;
                if (old_next) old_next->prev = p;
                break;
            }
            p = p->next;
        }
        
        return head;
    }
};