// 357. Count Numbers with Unique Digits

// Runtime: 4 ms, faster than 54.73% of C++ online submissions for Count Numbers with Unique Digits.
// Memory Usage: 8.2 MB, less than 83.33% of C++ online submissions for Count Numbers with Unique Digits.

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // [0,1) [0,10) [1,100)
        static vector<int> v{1, 10, 91};
        if (n >= 11)
            n = 10;
        const int size = v.size();
        for (int i = size; i <= n; ++i) {
            int pre = v[i - 1];
            int cnt = 9;
            for (int j = 1; j < i; ++j) 
                cnt *= (10 - j);
            v.push_back(cnt + pre);
        }
        return v[n];
    }
};