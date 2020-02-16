// 60. Permutation Sequence

// Runtime: 176 ms, faster than 24.40% of C++ online submissions for Permutation Sequence.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Permutation Sequence.

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = '1'; i <= '0' + n; ++i)
            ans.push_back(i);
        while (k > 1) {
            int i = n - 1;
            while (i >= 1) {
                if (ans[i - 1] < ans[i]) {
                    int j = n - 1;
                    while (ans[j] < ans[i - 1]) 
                        --j;
                    swap(ans[j], ans[i - 1]);
                    
                    j = n - 1;
                    while (i < j) 
                        swap(ans[i++], ans[j--]);
                    
                    break;
                }
                --i;
            }
            if (i == 0) {
                int j = n - 1;
                while (i < j) 
                    swap(ans[i++], ans[j--]);
            }
            --k;
        }
        return ans;
    }
};