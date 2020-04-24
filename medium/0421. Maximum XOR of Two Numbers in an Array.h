// 421. Maximum XOR of Two Numbers in an Array

class Solution {
    struct Node {
        Node(int v = -1) : val(v), zero(nullptr), one(nullptr) {}  
        int val;
        Node* zero;
        Node* one;
    };
    
    void build(int num, int i, Node* node) {
        if (i < 0) {
            node->val = num;
            return;
        }
        if (num & (1 << i)) {
            if (!node->one) node->one = new Node();
            build(num, i - 1, node->one);
        } else {
            if (!node->zero) node->zero = new Node();
            build(num, i - 1, node->zero);
        }
    }
    
    Node root;
    
    void print() {
        deque<Node*> nodes;
        nodes.push_back(&root);
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                auto node = nodes.front();
                nodes.pop_front();
                if (node->zero) nodes.push_back(node->zero);
                if (node->one) nodes.push_back(node->one);
                
                cout << (node && node->zero ? "0" : "?") << (node && node->one ? "1" : "?") << " ";
            }
            cout << endl;
        }
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        // for (int num : nums) cout << bitset<32>(num) << "  " << num <<endl;
        for (int num : nums) build(num, 30, &root);
        // print();
        
        Node* node = &root;
        while (node) {
            if (node->zero && node->one) break;
            node = node->zero ? node->zero : node->one;
        }
        if (!node) return 0;
        return get_xor(node->zero, node->one);
    }
    
    int get_xor(Node* zero, Node* one) {
        if (zero->val >= 0 && one->val >= 0) return zero->val ^ one->val;
        
        auto L0 = zero->zero;
        auto L1 = zero->one;
        
        auto R0 = one->zero;
        auto R1 = one->one;
        
        if (!L1) {
            if (R1) return get_xor(L0, R1);
            else return get_xor(L0, R0);
        }
        
        if (!L0) {
            if (R0) return get_xor(L1, R0);
            else return get_xor(L1, R1);
        }
        
        return max(get_xor(L0, R1), get_xor(L1, R0));
    }
};