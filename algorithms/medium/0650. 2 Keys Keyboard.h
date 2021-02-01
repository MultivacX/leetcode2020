// 650. 2 Keys Keyboard

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 2 Keys Keyboard.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for 2 Keys Keyboard.

class Solution {
public:
    int minSteps(int n) {
        static unordered_map<int, int> m{{0, 0}, {1, 0}, {2, 2}, {3, 3}};
        if (m.count(n)) return m[n];
        // (n - i) % i == 0, n - i >= i
        // m[n] = m[i] + copy(i) + paste(i) * (n - i) / i
        m[n] = n;
        for (int i = 2; n - i >= i; ++i) {
            if ((n - i) % i) continue;
            m[n] = min(m[n], minSteps(i) + 1 + (n - i) / i);
        }
        return m[n];
    }
};