// 667. Beautiful Arrangement II

// Runtime: 24 ms, faster than 28.40% of C++ online submissions for Beautiful Arrangement II.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Beautiful Arrangement II.

// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans{1};
        int i = 2;
        int j = n;
        while (k > 1) {
            int diff0 = abs(i - ans.back());
            int diff1 = abs(j - ans.back());
            if (diff0 < diff1) ans.push_back(j--);
            else ans.push_back(i++);
            --k;
        }
        int diff0 = abs(i - ans.back());
        if (diff0 == 1) while (i <= j) ans.push_back(i++);
        else while (i <= j) ans.push_back(j--);
        return ans;
    }
};