// 1316. Distinct Echo Substrings

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int N = text.length();
        unordered_set<string> subs;
        for (int L = 1; L <= N / 2; ++L) {
            for (int i = 0; i <= N - L; ++i) {
                
            }
        }
        return subs.size();
    }
};

// Time Limit Exceeded
// 37 / 38 test cases passed.
/*class Solution {
    unordered_set<string> substrings;
    
    bool equal(const string& text, int i, const int L) {
        for (int l = 0; l < L; ++l, ++i)
            if (text[i] != text[i+L]) return false;
        string s(text.substr(i - L, 2 * L));
        if (substrings.count(s)) return false;
        substrings.insert(s);
        return true;
    }
    
public:
    int distinctEchoSubstrings(string text) {
        static const int64_t mod = 7919;
        static const int64_t base = 128;
        
        const int N = text.length();
        int ans = 0;
        // hashes[i] = HASH(text[i, L))
        vector<int> hashes(N, 0);
        for (int L = 1; L <= N / 2; ++L) {
            for (int i = 0; i <= N - L; ++i) 
                hashes[i] = (hashes[i] * base % mod + text[i+L-1]) % mod;
            
            // equal(text[i, L), text[i+L, i+L+L))
            for (int i = 0; i + 2 * L <= N; ++i) 
                if (hashes[i] == hashes[i+L] && equal(text, i, L)) ++ans;
        }
        return ans;
    }
};*/