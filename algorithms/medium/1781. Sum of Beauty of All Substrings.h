// 1781. Sum of Beauty of All Substrings
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

// Runtime: 328 ms, faster than 100.00% of C++ online submissions for Sum of Beauty of All Substrings.
// Memory Usage: 55.6 MB, less than 16.67% of C++ online submissions for Sum of Beauty of All Substrings.
    
class Solution {
public:
    int beautySum(string s) {
        const int n = s.length();
        int ans = 0;
        map<int, int> m;
        // optim: vector<int> a(26, 0) minmax_element
        for (int i = 0; i + 1 < n; ++i) {
            // reset
            m.clear();
            vector<int> a(26, 0);
            
            int x = s[i] - 'a';
            
            m[++a[x]] |= 1 << x;
            
            for (int j = i + 1; j < n; ++j) {
                int y = s[j] - 'a';
                
                if (a[y] > 0) m[a[y]] -= 1 << y;
                if (m[a[y]] == 0) m.erase(a[y]);
                m[++a[y]] |= 1 << y;
                
                ans += m.crbegin()->first - m.cbegin()->first;
            }
        }
        return ans;
    }
};