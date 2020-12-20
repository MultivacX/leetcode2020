// 422. Valid Word Square
// https://leetcode.com/problems/valid-word-square/

// Runtime: 12 ms, faster than 87.90% of C++ online submissions for Valid Word Square.
// Memory Usage: 9.2 MB, less than 67.74% of C++ online submissions for Valid Word Square.
    
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        const int M = words.size();
        for (int i = 0; i < M; ++i) {
            const string& a = words[i];
            const int L = a.length();
            if (M < L) return false;
            
            for (int k = 0; k < L; ++k) {
                const string& b = words[k];
                if (b.length() < i + 1) return false;
                if (a[k] != b[i]) return false;
            }
            for (int k = L; k < M; ++k) {
                const string& b = words[k];
                if (b.length() >= i + 1) return false;
            }
        }
        return true;
    }
};