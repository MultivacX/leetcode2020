// 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

// Runtime: 28 ms, faster than 65.36% of C++ online submissions for Minimum Adjacent Swaps to Reach the Kth Smallest Number.
// Memory Usage: 6.5 MB, less than 68.98% of C++ online submissions for Minimum Adjacent Swaps to Reach the Kth Smallest Number.
    
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string w(num);
        while (k) {
            next_permutation(begin(w), end(w));
            if (w > num) --k;
        }
        // cout << w << endl;
        const int n = num.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // if (num[i] == w[i]) continue;
            int j = i;
            while (num[j] != w[i]) ++j;
            while (j > i) {
                swap(num[j], num[j - 1]);
                --j;
                ++ans;
            }
        }
        return ans;
    }
};