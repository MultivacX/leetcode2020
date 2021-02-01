// 313. Super Ugly Number

// Runtime: 96 ms, faster than 61.70% of C++ online submissions for Super Ugly Number.
// Memory Usage: 10.7 MB, less than 33.33% of C++ online submissions for Super Ugly Number.

// Time Complexity: O(n * k).
// Space Complexity: O(n + k).

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        const int k = primes.size();
        vector<int> idxs(k, 0);
        vector<uint64_t> nums{1};
        while (nums.size() < n) {
            uint64_t num = INT_MAX;
            for (int i = 0; i < k; ++i) {
                if (nums[idxs[i]] >= num) continue;
                uint64_t v = nums[idxs[i]] * (uint64_t)primes[i];
                if (v < num && v > nums.back())
                    num = v;
            }
            
            for (int i = 0; i < k; ++i) {
                if (nums[idxs[i]] >= num) continue;
                uint64_t v = nums[idxs[i]] * (uint64_t)primes[i];
                if (v == num) ++idxs[i];
            }
            
            // cout << num << endl;
            nums.push_back(num);
        }
        return nums.back();
    }
};