// 202. Happy Number

// Runtime: 4 ms, faster than 70.19% of C++ online submissions for Happy Number.
// Memory Usage: 8.6 MB, less than 53.85% of C++ online submissions for Happy Number.

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && visited.count(n) == 0) {
            visited.insert(n);
            int t = n;
            n = 0;
            while (t) {
                int m = t % 10;
                t /= 10;
                n += m * m;
            }
        }
        return n == 1;
    }
};