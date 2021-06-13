// 1897. Redistribute Characters to Make All Strings Equal
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

// Runtime: 16 ms, faster than 66.67% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
// Memory Usage: 11.7 MB, less than 33.33% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
    
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int n = words.size();
        vector<int> k(26);
        for (const auto& w : words)
            for (char c : w)
                ++k[c - 'a'];
        for (int i : k)
            if (i % n != 0)
                return false;
        return true;
    }
};