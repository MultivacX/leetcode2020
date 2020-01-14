// 707. Design Linked List

// Runtime: 52 ms, faster than 41.14% of C++ online submissions for Design Linked List.
// Memory Usage: 19.2 MB, less than 77.78% of C++ online submissions for Design Linked List.

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) return -1;
        auto node = head->next;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = head->next;
        head->next = new Node(val);
        head->next->next = node;
        ++len;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = head;
        while (node->next) node = node->next;
        node->next = new Node(val);
        ++len;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len || index < 0) return;
        auto node = head;
        while (index) {
            node = node->next;
            --index;
        }
        auto tmp = node->next;
        node->next = new Node(val);
        node->next->next = tmp;
        ++len;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= len || index < 0) return;
        auto node = head;
        while (index) {
            node = node->next;
            --index;
        }
        auto tmp = node->next;
        node->next = tmp->next;
        delete tmp;
        --len;
    }
    
private:
    class Node {
    public:
        Node(int v) : val(v), next(nullptr) {}
        int val;
        Node* next;
    };
    
    Node* head;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */