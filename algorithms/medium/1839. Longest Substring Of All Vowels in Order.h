// 1839. Longest Substring Of All Vowels in Order
// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/

// Runtime: 124 ms, faster than 33.33% of C++ online submissions for Longest Substring Of All Vowels in Order.
// Memory Usage: 35.8 MB, less than 16.67% of C++ online submissions for Longest Substring Of All Vowels in Order.
    
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        static const unordered_map<char, char> m{
            {'a', 'a'}, {'e', 'a'}, {'i', 'e'}, {'o', 'i'}, {'u', 'o'}, 
        };
        int ans = 0;
        string t;
        for (char w : word) {
            if (t.empty()) {
                if (w == 'a') t += w;    
            } else if (t.back() == w) {
                t += w;
            } else if (t.back() == m.at(w)) {
                t += w;
            } else {
                t.clear();
                if (w == 'a') t += w;    
            }
            
            if (!t.empty() && t.back() == 'u')
                ans = max(ans, (int)t.length());
        }
        return ans;
    }
};