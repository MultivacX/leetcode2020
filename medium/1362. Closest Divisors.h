// 1362. Closest Divisors
// https://leetcode.com/problems/closest-divisors/

// Runtime: 12 ms, faster than 48.87% of C++ online submissions for Closest Divisors.
// Memory Usage: 6.5 MB, less than 24.76% of C++ online submissions for Closest Divisors.

class Solution {
    vector<int> find(const int n) {
        int a = 1;
        int b = n;
        int d = n - 1;
        for (int i = 2; i * i <= n; ++i) {
            int j = n / i;
            if (i * j != n || j - i >= d) continue;
            a = i;
            b = j;
            d = j - i;
        }
        return {a, b, d};
    }
    
public:
    vector<int> closestDivisors(int num) {
        auto n1 = find(num + 1);
        auto n2 = find(num + 2);
        auto* ans = n1.back() <= n2.back() ? &n1 : &n2;
        ans->pop_back();
        return *ans;
    }
};