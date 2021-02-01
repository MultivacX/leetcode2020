// 1073. Adding Two Negabinary Numbers
// https://leetcode.com/problems/adding-two-negabinary-numbers/

// Runtime: 8 ms, faster than 93.91% of C++ online submissions for Adding Two Negabinary Numbers.
// Memory Usage: 19.7 MB, less than 67.31% of C++ online submissions for Adding Two Negabinary Numbers.

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        // 001 + 001 = 110
        // 011 + 001 = 000
        // 011 + 011 = 010
        reverse(begin(arr1), end(arr1));
        reverse(begin(arr2), end(arr2));
        const int M = arr1.size();
        const int N = arr2.size();
        vector<int> ans(max(M, N) + 2, 0);
        int i = 0;
        int c0 = 0;
        int c1 = 0;
        while (i < ans.size()) {
            int a0 = i < M ? arr1[i] : 0;
            int b0 = i < N ? arr2[i] : 0;
            
            int v0 = a0 + b0 + c0; // v0: 0, 1, 2, 3
            // c1 : 0, 1
            if (v0 <= 1) {
                ans[i] = v0;
                c0 = c1;
                c1 = 0;
            } else if (c1 == 1) {
                v0 = v0 - c1 * 2;  
                ans[i] = v0;
                c0 = 0;
                c1 = 0;
            } else {
                ans[i] = v0 % 2;
                c0 = 1;
                c1 = 1;
            }
            ++i;
        }
        
        while (ans.size() > 1 && ans.back() == 0)
            ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }
};