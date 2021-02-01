// 1134. Armstrong Number
// https://leetcode.com/problems/armstrong-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Armstrong Number.
// Memory Usage: 6.2 MB, less than 90.63% of C++ online submissions for Armstrong Number.
    
class Solution {
public:
    bool isArmstrong(int N) {
        string S(to_string(N));
        int k = S.length();
        int n = 0;
        for (char c : S)
            n += pow(c - '0', k);
        return n == N;
    }
};