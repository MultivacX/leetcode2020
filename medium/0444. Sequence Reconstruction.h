// 444. Sequence Reconstruction
// https://leetcode.com/problems/sequence-reconstruction/

// Runtime: 216 ms, faster than 70.67% of C++ online submissions for Sequence Reconstruction.
// Memory Usage: 73.5 MB, less than 40.53% of C++ online submissions for Sequence Reconstruction.
    
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false; // !!!
        
        const int n = org.size();
        vector<unordered_set<int>> pres(n + 1);
        vector<int> degrees(n + 1);
        for (const auto& s : seqs) {
            for (int v : s) if (v < 1 || v > n) return false; // !!!
            for (int i = s.size() - 1; i > 0; --i) 
                if (pres[s[i]].insert(s[i - 1]).second) 
                    ++degrees[s[i - 1]];
        }
        
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (degrees[i] > 0) continue;
            if (cur != 0) return false;
            cur = i;
        }
        
        int idx = n - 1;
        while (idx >= 0) {
            if (cur != org[idx]) return false;
            --idx;
            int nxt = 0;
            for (int pre : pres[cur]) {
                --degrees[pre];
                if (degrees[pre] > 0) continue;
                if (degrees[pre] < 0) return false;
                if (nxt != 0) return false;
                nxt = pre;
            }
            cur = nxt;
        }
        return idx < 0;
    }
};