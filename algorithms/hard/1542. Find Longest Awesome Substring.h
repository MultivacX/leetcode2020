// 1542. Find Longest Awesome Substring
// https://leetcode.com/problems/find-longest-awesome-substring/

// Runtime: 228 ms, faster than 43.02% of C++ online submissions for Find Longest Awesome Substring.
// Memory Usage: 11 MB, less than 35.75% of C++ online submissions for Find Longest Awesome Substring.
    
class Solution {
public:
    int longestAwesome(string s) {
        // 0: even cnt, 1: odd cnt
        // 98_7654_3210
        // 00_0000_0000, s[0, i]
        unordered_map<int, int> prefix{{0, -1}};
        int ans = 0;
        for (int i = 0, key = 0; i < s.length(); ++i) {
            int bit = 1 << (s[i] - '0');
            key = (key & bit) ? (key - bit) : (key + bit);

            for (int j = 0; j <= 9; ++j) {
                int b = 1 << j;
                int k = (key & b) ? (key - b) : (key + b);
                if (prefix.count(k) && ans < i - prefix[k]) 
                    ans = i - prefix[k];
            }
            
            if (prefix.count(key) == 0) prefix.insert({key, i});
            else if (ans < i - prefix[key]) ans = i - prefix[key];
        }
        return ans;
    }
};


// TLE
// 153 / 153 test cases passed, but took too long.
class Solution {
    int countBits(int num) {
        int cnt = 0;
        for (int i = 0; i <= 9; ++i)
            if (num & (1 << i))
                ++cnt;
        return cnt;
    }
    
public:
    int longestAwesome(string s) {
        // 0: even cnt, 1: odd cnt
        // 98_7654_3210
        // 00_0000_0000, s[0, i]
        unordered_map<int, int> prefix{{0, -1}};
        int ans = 0;
        for (int i = 0, key = 0; i < s.length(); ++i) {
            int bit = 1 << (s[i] - '0');
            key = (key & bit) ? (key - bit) : (key + bit);
            
            for (const auto& [k, j] : prefix) 
                if (countBits(k ^ key) <= 1 && ans < i - j)
                    ans = i - j;
            
            if (prefix.count(key) == 0) prefix.insert({key, i});
        }
        return ans;
    }
};