// 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

// Runtime: 32 ms, faster than 5.05% of C++ online submissions for Find the Minimum Number of Fibonacci Numbers Whose Sum Is K.
// Memory Usage: 23.9 MB, less than 100.00% of C++ online submissions for Find the Minimum Number of Fibonacci Numbers Whose Sum Is K.

class Solution {
    void count(const vector<int> fibonaccis, int i, int cnt, int k, int& ans) {
        if (cnt >= ans) return;
        
        if (k == 0) {
            ans = min(ans, cnt);
            return;
        }
        
        while (i >= 0 && fibonaccis[i] > k) --i;
        if (i < 0) return;
        
        int c = k / fibonaccis[i];
        int remain = k - fibonaccis[i] * c;
        count(fibonaccis, i, cnt + c, remain, ans);
    }
    
public:
    int findMinFibonacciNumbers(int k) {
        // a Fibonacci number could be used multiple times.
        static const vector<int> fibonaccis{1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170};
        
        int ans = k;
        int i = lower_bound(begin(fibonaccis), end(fibonaccis), k) - begin(fibonaccis);
        while (i >= 0) 
            count(fibonaccis, i--, 0, k, ans);
        return ans;
    }
};