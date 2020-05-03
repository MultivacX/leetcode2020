// 816. Ambiguous Coordinates

// Runtime: 28 ms, faster than 26.67% of C++ online submissions for Ambiguous Coordinates.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Ambiguous Coordinates.

// Time Complexity: O(S.length() * S.length() * S.length()).
// Space Complexity: O(S.length() * S.length() * S.length()).

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        const int L = 1;
        const int R = S.length() - 2;
        for (int i = L; i < R; ++i) {
            // [L, i], [i + 1, R]
            // skip "0...0"
            if (L < i && S[L] == '0' && S[i] == '0') continue;
            if (i + 1 < R && S[i + 1] == '0' && S[R] == '0') continue;
            
            auto l = get_num(S.substr(L, i - L + 1));
            auto r = get_num(S.substr(i + 1, R - (i + 1) + 1));
            for (const string& x : l) {
                for (const string& y : r) {
                    ans.emplace_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }
    
    vector<string> get_num(const string& S) {
        const int N = S.length();
        if (N == 1) return {S};
        if (S[0] == '0') return {"0." + S.substr(1)};
        if (S.back() == '0') return {S};
        
        vector<string> nums{S};
        const int L = 0;
        const int R = N - 1;
        for (int i = L; i < R; ++i) 
            nums.emplace_back(S.substr(0, i + 1) + "." + S.substr(i + 1));
        return nums;
    }
};