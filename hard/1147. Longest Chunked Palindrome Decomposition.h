// 1147. Longest Chunked Palindrome Decomposition

// Runtime: 4 ms, faster than 83.33% of C++ online submissions for Longest Chunked Palindrome Decomposition.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Longest Chunked Palindrome Decomposition.

class Solution {
    static const int M = 7919;
    static const int BASE = 26;
    
    bool equal(const string& text, const int length, int i, int j){
        for (int k = 0; k < length; ++k) {
            if (text[i] != text[j]) return false;
            ++i;
            ++j;
        }
        return true;
    }
    
public:
    int longestDecomposition(string text) {
        const int N = text.length();
        int ans = 0;
        int i = 0;
        int j = N - 1;
        while (i <= j) {
            if (i == j) {
                ans += 1;
                break;
            }
            
            const int MAX_L = (j - i + 1) / 2;
            // [i, i + len) (j - len, j]
            int hash_l = 0;
            int hash_r = 0;
            int len = 1;
            int ii = i;
            int jj = j;
            int power = 1;
            bool found = false;
            while (len <= MAX_L) {
                hash_l = (hash_l * BASE % M + text[ii]) % M;
                hash_r = (hash_r + text[jj] * power % M) % M;
                
                if (hash_l == hash_r && equal(text, len, i, j - len + 1)) {
                    found = true;
                    break;
                }
                
                ++len;
                ++ii;
                --jj;
                power = power * BASE % M;
            }
            
            if (found) {
                cout << "T: " << text.substr(i, len) << endl;
                ans += 2;
                i += len;
                j -= len;
            } else {
                cout << "F: " << text.substr(i, j - i + 1) << endl;
                ans += 1;
                break;
            }
        }
        return ans;
    }
};