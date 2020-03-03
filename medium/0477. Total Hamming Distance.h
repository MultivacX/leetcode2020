// 477. Total Hamming Distance

// Runtime: 68 ms, faster than 60.69% of C++ online submissions for Total Hamming Distance.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Total Hamming Distance.

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        int d = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 1 << i;
            int ones = 0;
            for (int num : nums) if (bit & num) ++ones;
            d += ones * (n - ones);
        }
        return d;
    }
};

// Time Limit Exceeded
// 36 / 47 test cases passed.
/*class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int n = nums.size();
        int d = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                d += dist(nums[i], nums[j]);
        return d;
    }
    
    int dist(int num1, int num2) {
        int cnt = 0;
        int num = num1 ^ num2;
        for (int i = 0; i < 32; ++i)
            if ((1 << i) & num)
                ++cnt;
        return cnt;
    }
};*/