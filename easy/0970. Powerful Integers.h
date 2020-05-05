// 970. Powerful Integers

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Powerful Integers.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Powerful Integers.

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        int X = 1;
        while (X <= bound) {
            int Y = 1;
            while (X + Y <= bound) {
                ans.emplace(X + Y);
                if (Y * y == Y) break;
                Y *= y;
            }
            if (X * x == X) break;
            X *= x;
        }
        return vector<int>(begin(ans), end(ans));
    }
};