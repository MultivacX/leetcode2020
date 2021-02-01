// 146. LRU Cache

// Runtime: 112 ms, faster than 71.39% of C++ online submissions for LRU Cache.
// Memory Usage: 38 MB, less than 79.27% of C++ online submissions for LRU Cache.

class LRUCache {
    class Node {
    public:
        Node(int k = 0, int v = 0) : key(k), val(v) {}
        
        int key;
        int val;
        Node* prev{nullptr};
        Node* next{nullptr};
    };
    
    Node head;
    Node tail;
    unordered_map<int, Node*> nodes;
    int capacity;
    
    void remove(Node* node, bool delete_node) {
        auto prev = node->prev;
        auto next = node->next;
        if (prev) prev->next = next;
        if (next) next->prev = prev;
        
        if (delete_node) {
            nodes.erase(node->key);
            delete node;   
        }
    }
    
    void update(Node* node) {
        remove(node, false);

        auto prev = tail.prev;
        prev->next = node;
        auto next = &tail;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }
    
public:
    LRUCache(int c) : capacity(c) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        auto it = nodes.find(key);
        if (it == nodes.end())
            return -1;
        update(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = nodes.find(key);
        if (it == nodes.end()) {
            if (nodes.size() == capacity) 
                remove(head.next, true);
            nodes.insert({key, new Node(key, value)});
        } else {
            nodes[key]->val = value;
        }
        update(nodes[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */