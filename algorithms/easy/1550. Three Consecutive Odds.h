// 1550. Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/

// Runtime: 4 ms, faster than 92.27% of C++ online submissions for Three Consecutive Odds.
// Memory Usage: 8.4 MB, less than 89.85% of C++ online submissions for Three Consecutive Odds.
    
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int N = arr.size();
        int i = 0;
        while (i + 2 < N) {
            if ((arr[i + 2] & 1) == 0) {
                i += 3;
                continue;
            }
            if ((arr[i + 1] & 1) == 0) {
                i += 2;
                continue;
            }
            if ((arr[i] & 1) == 0) {
                i += 1;
                continue;
            }
            
            return true;
        }
        return false;
    }
};