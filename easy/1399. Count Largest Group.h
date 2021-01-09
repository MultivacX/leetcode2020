// 1399. Count Largest Group
// https://leetcode.com/problems/count-largest-group/

// Runtime: 12 ms, faster than 46.19% of C++ online submissions for Count Largest Group.
// Memory Usage: 6.8 MB, less than 10.62% of C++ online submissions for Count Largest Group.
    
class Solution {
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i) ++m[sum(i)];
        map<int, int> k;
        for (auto it : m) ++k[it.second];
        return k.crbegin()->second;
    }
};