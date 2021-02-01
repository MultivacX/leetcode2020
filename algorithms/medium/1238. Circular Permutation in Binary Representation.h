// 1238. Circular Permutation in Binary Representation
// https://leetcode.com/problems/circular-permutation-in-binary-representation/

// Runtime: 24 ms, faster than 81.46% of C++ online submissions for Circular Permutation in Binary Representation.
// Memory Usage: 16.7 MB, less than 96.07% of C++ online submissions for Circular Permutation in Binary Representation.
    
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n, 0);
        ans[1] = 1;
        
        // cout << 1 << ":" << endl;
        // for (int j = 0; j <= 1; ++j) 
        //     cout << bitset<16>(ans[j]) << endl;
        
        int idx = start == 1 ? 1 : 0;
        
        int i = 2, L = 2;
        while (i < (1 << n)) {
            // mirror : [0, i) [i, i*2)
            for (int l = 0, r = i * 2 - 1, b = 1 << (L - 1); l < r; ++l, --r) {
                ans[r] = ans[l] | b;
                if (start == ans[r]) idx = r;
            }
            // cout << L << ":" << endl;
            // for (int j = i; j < i * 2; ++j) 
            //     cout << bitset<16>(ans[j]) << endl;
            i *= 2;
            ++L;
        }
        
        if (idx == 0) return ans;
        reverse(begin(ans), begin(ans) + idx);
        reverse(begin(ans) + idx, end(ans));
        reverse(begin(ans), end(ans));
        return ans;
    }
};
