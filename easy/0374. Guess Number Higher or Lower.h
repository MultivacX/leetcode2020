// 374. Guess Number Higher or Lower

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess Number Higher or Lower.
// Memory Usage: 8.2 MB, less than 83.33% of C++ online submissions for Guess Number Higher or Lower.

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int begin = 1;
        int end = n;
        while (begin <= end) {
            int mid = begin + (end - begin + 1) / 2;
            int ans = guess(mid);
            if (ans == -1) end = mid - 1;
            else if (ans == 1) begin = mid + 1;
            else return mid;
        }
        return 0;
    }
};