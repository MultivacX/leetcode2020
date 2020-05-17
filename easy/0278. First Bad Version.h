// 278. First Bad Version

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for First Bad Version.

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Time Complexity: O(lg(n)).
// Space Complexity: O(lg(n)).

class Solution {
public:
    int firstBadVersion(int n) {
        unordered_set<int> badVersions;
        int l = 1;
        int r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            // printf("%d %d %d\n", l, m, r);
            if (badVersions.count(m) || isBadVersion(m)) {
                if (m == 1) return m;
                if (isBadVersion(m - 1) == false) return m;
                else badVersions.insert(m - 1);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return 0;
    }
};