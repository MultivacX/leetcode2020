// 946. Validate Stack Sequences

// Runtime: 8 ms, faster than 90.18% of C++ online submissions for Validate Stack Sequences.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Validate Stack Sequences.

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int N = pushed.size();
        if (N <= 1) return true;
        
        stack<int> s;
        s.push(pushed[0]);
        
        int next = 1;
        int target = 0;
        
        while (true) {
            while (target < N && !s.empty() && s.top() == popped[target]) {
                s.pop();
                ++target;
            } 
            if (next < N) {
                s.push(pushed[next++]);
            } else {
                return s.empty();
            }
        }
        return s.empty();
    }
};