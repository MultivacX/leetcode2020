// 1295. Find Numbers with Even Number of Digits
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// Runtime: 8 ms, faster than 87.51% of C++ online submissions for Find Numbers with Even Number of Digits.
// Memory Usage: 9.9 MB, less than 98.03% of C++ online submissions for Find Numbers with Even Number of Digits.
    
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            if (10 <= i && i <= 99) ++ans;
            else if (1000 <= i && i <= 9999) ++ans;
            else if (i == 100000) ++ans;
        }
        return ans;
    }
};