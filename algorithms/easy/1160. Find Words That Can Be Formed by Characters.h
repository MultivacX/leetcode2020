// 1160. Find Words That Can Be Formed by Characters
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

// Runtime: 84 ms, faster than 55.86% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 20.8 MB, less than 57.29% of C++ online submissions for Find Words That Can Be Formed by Characters.
    
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> m(26, 0);
        for (char c : chars) ++m[c - 'a'];
        
        int ans = 0;
        for (const auto& w : words) {
            vector<int> n(26, 0);
            for (char c : w) ++n[c - 'a'];
            bool good = true;
            for (int i = 0; i < 26 && good; ++i)
                if (m[i] < n[i])
                    good = false;
            if (good) ans += w.length();
        }
        return ans;
    }
};