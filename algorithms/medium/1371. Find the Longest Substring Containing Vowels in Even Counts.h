// 1371. Find the Longest Substring Containing Vowels in Even Counts

// Runtime: 256 ms, faster than 45.23% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.

// Time Complexity: O(s.length()).
// Space Complexity: O(1).

class Solution {
public:
    int findTheLongestSubstring(string s) {
        static unordered_map<char, int> vowels{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        
        int ans = 0;
        int mask = 0;
        // {mask, left-most idx}
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.count(s[i]) > 0) {
                mask = mask ^ (1 << vowels[s[i]]);
                if (m.count(mask) == 0) m[mask] = i;
            } 
            // cout << bitset<5>(mask) << " " << i - m[mask] << endl;
            ans = max(ans, i - m[mask]);
        }
        return ans;
    }
};