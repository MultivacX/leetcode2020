// 1218. Longest Arithmetic Subsequence of Given Difference
// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

// Runtime: 304 ms, faster than 62.80% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// Memory Usage: 58 MB, less than 10.75% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.

class Solution {
    unordered_map<int, int> m;
    
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int N = arr.size();
        vector<int> lens(N, 1);
        for (int i = N - 1; i >= 0; --i) 
            f(arr, difference, lens, i);
        return *max_element(begin(lens), end(lens));
    }
    
    void f(vector<int>& arr, int difference, vector<int>& lens, int i) {
        int val = arr[i];
        if (lens[i] > 1) {
            m[val] = i;
            return;
        }
        
        int next_val = val + difference;
        if (m.find(next_val) == m.end()) { 
            m[val] = i; 
            return; 
        }
        
        int next_i = m[next_val];
        lens[i] = 1 + lens[next_i];
        m[val] = i;
    }
};