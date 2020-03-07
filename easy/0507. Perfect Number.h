// 507. Perfect Number

// Runtime: 532 ms, faster than 31.68% of C++ online submissions for Perfect Number.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Perfect Number.

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 5)
            return false;
        
        unordered_set<int> divisors;
        divisors.emplace(1);
        divisors.emplace(num);
        int sum = 1;
        for (int i = 2; i < num / 2; ++i) {
            if (num % i) continue;
            if (divisors.count(i)) break;
            int j = num / i;
            sum += i + j;
            divisors.emplace(i);
            divisors.emplace(j);
        }
        return sum == num;
    }
};