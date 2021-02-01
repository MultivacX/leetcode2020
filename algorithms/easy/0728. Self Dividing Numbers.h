// 728. Self Dividing Numbers
// https://leetcode.com/problems/self-dividing-numbers/

// Runtime: 4 ms, faster than 44.36% of C++ online submissions for Self Dividing Numbers.
// Memory Usage: 6.9 MB, less than 24.34% of C++ online submissions for Self Dividing Numbers.
    
class Solution {
    bool issdn(int num) {
        int val = num;
        while (val > 0) {
            int d = val % 10;
            if (d == 0 || num % d)
                return false;
            val /= 10;
        }
        return true;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; ++num) 
            if (issdn(num)) ans.push_back(num);
        return ans;
    }
};