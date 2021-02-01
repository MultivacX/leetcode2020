// 708. Insert into a Sorted Circular Linked List
// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

// Runtime: 12 ms, faster than 85.54% of C++ online submissions for Insert into a Sorted Circular Linked List.
// Memory Usage: 8.5 MB, less than 29.43% of C++ online submissions for Insert into a Sorted Circular Linked List.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        auto p = head;
        auto q = p->next;
        auto m = p;
        bool b = false;
        while (!b) {
            // cout << p->val << "->" << q->val << endl;
            if (p->val <= insertVal && insertVal < q->val) {
                p->next = new Node(insertVal, q);
                return head;
            }
            p = q;
            q = q->next;
            if (p->val >= m->val) m = p; 
            b = p == head;
        }
        m->next = new Node(insertVal, m->next);
        return head;
    }
};