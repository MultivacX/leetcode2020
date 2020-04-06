// 1345. Jump Game IV

// Runtime: 672 ms, faster than 5.04% of C++ online submissions for Jump Game IV.
// Memory Usage: 42.2 MB, less than 100.00% of C++ online submissions for Jump Game IV.

class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        if (N == 1) return 0;
        
        // {val, {idx, ...}}
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < N; ++i) m[arr[i]].insert(i);
        
        int target = N - 1;

        int steps = 0;
        deque<int> q;
        q.push_back(0);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front(); 
                q.pop_front();
                // cout << steps << ":[" << i << "]=" << arr[i] << ", "; 
                if (i == target) return steps;
                jump(arr, m, i, q);
            }
            // cout << endl;
            ++steps;
        }
        return steps;
    }
    
    void jump(const vector<int>& arr, unordered_map<int, unordered_set<int>>& m, int i, deque<int>& q) {
        int v = arr[i];
        if (m.count(v)) m[v].erase(i);
        
        auto _jump = [&](int j){
            const int N = arr.size();
            if (j < 0 || j >= N) return;
            
            int val = arr[j];
            if (m.count(val) == 0 || m[val].count(j) == 0) return;
            
            q.push_back(j);
            m[val].erase(j);
        };
        
        _jump(i - 1);
        _jump(i + 1);
        
        if (m.count(v) == 0) return; 
        for (int j : m[v])
            q.push_back(j);
        m.erase(v);
    }
};