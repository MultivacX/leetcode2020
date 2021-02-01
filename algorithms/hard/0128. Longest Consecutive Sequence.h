// 128. Longest Consecutive Sequence

// Runtime: 12 ms, faster than 68.73% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 10.1 MB, less than 67.31% of C++ online submissions for Longest Consecutive Sequence.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        int ans = 0;
        for (int i : nums) {
            if (s.count(i + 1)) continue;
            
            s.erase(i);
            int cnt = 1;
            int j = i - 1;
            while (s.count(j)) {
                ++cnt; 
                s.erase(j);
                --j;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};