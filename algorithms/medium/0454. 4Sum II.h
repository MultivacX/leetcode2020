// 454. 4Sum II

// Runtime: 176 ms, faster than 74.52% of C++ online submissions for 4Sum II.
// Memory Usage: 24.4 MB, less than 95.45% of C++ online submissions for 4Sum II.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (int a : A) 
            for (int b : B)
                ++m[-a-b];
        int ans = 0;
        for (int c : C) 
            for (int d : D)
                if (m.count(c + d)) 
                    ans += m[c + d];
        return ans;
    }
};