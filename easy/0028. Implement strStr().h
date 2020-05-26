// 28. Implement strStr()

// Runtime: 4 ms, faster than 91.35% of C++ online submissions for Implement strStr().
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Implement strStr().

class Solution {
    bool equal(const string& haystack, const string& needle, int i) {
        for (int j = 0; j < needle.length(); ++j)
            if (haystack[i++] != needle[j]) return false;
        return true;
    }
    
public:
    int strStr(string haystack, string needle) {
        const int M = haystack.length();
        const int N = needle.length();
        if (M == 0) return N == 0 ? 0 : -1;
        if (N == 0) return 0;
        if (M < N) return -1;
        
        static const int64_t mod = 7919;
        static const int64_t base = 128;
        
        int64_t H = 0;
        for (int i = 0; i < N; ++i) H = (H * base % mod + needle[i]) % mod;
        
        int64_t h = 0;
        for (int i = 0; i < N; ++i) h = (h * base % mod + haystack[i]) % mod;
        
        if (H == h && equal(haystack, needle, 0)) return 0;
        
        // cout << H << " " << h << " : ";
        // for (int j = 0; j <= 0 + N - 1; ++j) cout << haystack[j]; cout << endl;
        
        int64_t power = 1;
        for (int i = 1; i < N; ++i) power = power * base % mod;
        
        for (int i = 1; i < M - N + 1; ++i) {
            h = (h - haystack[i - 1] * power % mod + mod) % mod;
            h = (h * base % mod + haystack[i + N - 1]) % mod;
            
            // cout << H << " " << h << " : ";
            // for (int j = i; j <= i + N - 1; ++j) cout << haystack[j]; cout << endl;
            
            if (H == h && equal(haystack, needle, i)) return i;
        }
        
        return -1;
    }
};