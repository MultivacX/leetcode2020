// 1756. Design Most Recently Used Queue
// https://leetcode.com/problems/design-most-recently-used-queue/

// Runtime: 156 ms, faster than 23.91% of C++ online submissions for Design Most Recently Used Queue.
// Memory Usage: 38.9 MB, less than 50.00% of C++ online submissions for Design Most Recently Used Queue.
    
class MRUQueue {
    // int n;
    list<int> l;
    
public:
    MRUQueue(int n) {
        // this->n = n;
        for (int i = 1; i <= n; ++i)
            l.push_back(i);
    }
    
    int fetch(int k) {
        int ans = 0;
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (--k == 0) {
                ans = *it;
                l.erase(it);
                break;
            }
        }
        l.push_back(ans);
        return ans;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */