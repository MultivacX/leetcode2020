// 1718. Construct the Lexicographically Largest Valid Sequence
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

// Runtime: 4 ms, faster than 61.22% of C++ online submissions for Construct the Lexicographically Largest Valid Sequence.
// Memory Usage: 6.2 MB, less than 92.86% of C++ online submissions for Construct the Lexicographically Largest Valid Sequence.
    
class Solution {
    int N;
    vector<int> seq;
    vector<int> used;
    
    bool dfs(int i) {
        if (i >= seq.size()) return true;
        if (seq[i]) return dfs(i + 1);
        
        for (int j = N; j > 0; --j) {
            if (used[j]) continue;
            if (j != 1 && (i + j >= seq.size() || seq[i + j])) continue;
            
            used[j] = true;
            seq[i] = j;
            if (j != 1) seq[i + j] = j;
            if (dfs(i + 1)) return true;
            used[j] = false;
            seq[i] = 0;
            if (j != 1) seq[i + j] = 0;
        }
        
        return false;
    }
    
public:
    vector<int> constructDistancedSequence(int n) {
        N = n;
        seq.resize((n - 1) * 2 + 1, 0);
        used.resize(n + 1, 0);
        dfs(0);
        return seq;
    }
};