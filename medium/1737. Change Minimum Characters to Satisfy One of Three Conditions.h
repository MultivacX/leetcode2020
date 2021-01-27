// 1737. Change Minimum Characters to Satisfy One of Three Conditions
// https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/

// Runtime: 40 ms, faster than 95.82% of C++ online submissions for Change Minimum Characters to Satisfy One of Three Conditions.
// Memory Usage: 14.8 MB, less than 37.04% of C++ online submissions for Change Minimum Characters to Satisfy One of Three Conditions.
    
class Solution {
    int strictlyLess(vector<int> A, vector<int> B) {
        // A < B
        for (int i = 24; i >= 0; --i) A[i] += A[i + 1];
        for (int j = 1; j < 26; ++j) B[j] += B[j - 1];
        
        int changes = INT_MAX;
        // change A[k....25] to A[0]
        // change B[0...k-1] to B[25]
        for (int k = 1; k < 26; ++k)
            changes = min(changes, A[k] + B[k - 1]);
        return changes;
    }
    
public:
    int minCharacters(string a, string b) {
        vector<int> A(26, 0), B(26, 0);
        for (char c : a) ++A[c - 'a'];
        for (char c : b) ++B[c - 'a'];
        int k = a.length() - *max_element(begin(A), end(A)) +
                b.length() - *max_element(begin(B), end(B));
        return min(min(strictlyLess(A, B), strictlyLess(B, A)), k);
    }
};