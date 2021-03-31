// 1806. Minimum Number of Operations to Reinitialize a Permutation
// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

// Runtime: 20 ms, faster than 65.46% of C++ online submissions for Minimum Number of Operations to Reinitialize a Permutation.
// Memory Usage: 6.5 MB, less than 60.54% of C++ online submissions for Minimum Number of Operations to Reinitialize a Permutation.

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr0(n);
        for (int i = 0; i < n; ++i)
            arr0[i] = i;
        vector<int> arr1(arr0);
        
        int ans = 0;
        while (true) {
            ++ans;
            for (int i = 0; i < n; ++i)
                arr1[i] = (i % 2 == 0) ? arr0[i / 2] : arr0[n / 2 + (i - 1) / 2];
            if (arr1[1] == 1) {
                bool b = true;
                for (int i = 0; i < n; ++i) {
                    if (arr1[i] != i) {
                        b = false;
                        break;       
                    }
                }
                if (b) break;
            }
            swap(arr0, arr1);
        }
        return ans;
    }
};