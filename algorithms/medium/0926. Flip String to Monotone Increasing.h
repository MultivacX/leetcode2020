// 926. Flip String to Monotone Increasing

// Runtime: 8 ms, faster than 87.25% of C++ online submissions for Flip String to Monotone Increasing.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Flip String to Monotone Increasing.

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int i = 0;
        while (i < S.length() && S[i] == '0') ++i;
        
        int j = S.length() - 1;
        while (j >= 0 && S[j] == '1') --j;
        
        if (i >= j) return 0;
        
        int cnt0 = 0;
        int cnt1 = 0;
        for (int k = i; k <= j; ++k) 
            S[k] == '0' ? ++cnt0 : ++cnt1;
        int ans = min(cnt0, cnt1);
        int k = i;
        int flips1 = 0;
        while (k <= j && cnt0 > 0 && cnt1 > 0) {
            if (S[k] == '1') {
                --cnt1;
                ++flips1;
            } else {
                --cnt0;
            }
            ans = min(ans, flips1 + cnt0);
            ++k;
        }
        return ans;
    }
};

// Wrong Answer
// 72 / 81 test cases passed.
// "10011111110010111011"
/* class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int i = 0;
        while (i < S.length() && S[i] == '0') ++i;
        
        int j = S.length() - 1;
        while (j >= 0 && S[j] == '1') --j;
        
        int cnt0 = 0;
        int cnt1 = 0;
        for (int k = i; k <= j; ++k) S[k] == '0' ? ++cnt0 : ++cnt1;
        return min(cnt0, cnt1);
    }
}; */