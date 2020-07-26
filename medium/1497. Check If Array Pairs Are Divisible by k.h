// 1497. Check If Array Pairs Are Divisible by k
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

// Runtime: 252 ms, faster than 91.55% of C++ online submissions for Check If Array Pairs Are Divisible by k.
// Memory Usage: 61.3 MB, less than 100.00% of C++ online submissions for Check If Array Pairs Are Divisible by k.
    
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainders(k / 2 + 1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            int r = (k + arr[i] % k) % k;
            // cout << arr[i] << " " << r << endl;
            if (r == 0) ++remainders[0];
            else if (r <= k / 2) ++remainders[r];
            else --remainders[k - r];
        }
        if (remainders[0] & 1) return false;
        for (int i = 1; i < k / 2 + 1; ++i) {
            if (remainders[i] == 0) continue;
            if (2 * i == k && remainders[i] % 2 == 0) continue;
            return false;
        }
        return true;
    }
};a