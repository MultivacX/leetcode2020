// 1388. Pizza With 3n Slices

// Time Limit Exceeded
/*class Solution {
public:
    struct Node {
        int val;
        int idx;
        Node* pre;
        Node* nxt;
    };
    
    int maxSizeSlices(vector<int>& slices) {
        const int N = slices.size();
        vector<Node*> nodes(N);
        for (int i = 0; i < N; ++i) {
            nodes[i] = new Node();
            nodes[i]->val = slices[i];
            nodes[i]->idx = i;
        }
        for (int i = 0; i < N; ++i) {
            nodes[i]->pre = nodes[(i - 1 + N) % N];
            nodes[i]->nxt = nodes[(i + 1) % N];
        }
        
        return pick(nodes[0], N);
    }
    
    bitset<500> visited;
    unordered_map<bitset<500>, unordered_map<int, int>> m;
    
    int pick(Node* node, int N) {
        if (N == 3) return max(node->val, max(node->pre->val, node->nxt->val));
        
        int idx = node->idx;
        visited.set(idx);
        if (m.count(visited) && m[visited].count(N)) {
            int size = m[visited][N];
            visited.set(idx, false);
            return size;
        }
        
        int size = 0;
        for (int i = 0; i < N; ++i) {
            // ... -- pre -- [node->pre -- node -- node->nxt] -- nxt -- ...
            
            // pick
            visited.set(node->idx);
            auto pre = node->pre->pre;
            auto nxt = node->nxt->nxt;
            pre->nxt = nxt;
            nxt->pre = pre;
            
            // cout << N << ": " << node->pre->val << " -- (" << node->val << ") -- " << node->nxt->val << endl;
            size = max(size, node->val + pick(nxt, N - 3));
            
            // reset
            visited.set(node->idx, false);
            pre->nxt = node->pre;
            nxt->pre = node->nxt;
            
            node = node->nxt;
        }
        
        visited.set(idx);
        m[visited][N] = size;
        visited.set(idx, false);
        return size;
    }
};*/