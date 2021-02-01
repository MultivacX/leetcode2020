// 137. Single Number II

// Runtime: 12 ms, faster than 76.19% of C++ online submissions for Single Number II.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Single Number II.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        for (int num : nums) 
            for (int i = 0; i < 32; ++i) 
                if (num & (1 << i)) 
                    ++count[i];
            
        int num = 0;
        for (int i = 0; i < 32; ++i) 
            if (count[i] % 3)
                num |= 1 << i;
        return num;
    }
};