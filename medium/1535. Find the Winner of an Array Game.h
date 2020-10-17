// 1535. Find the Winner of an Array Game
// https://leetcode.com/problems/find-the-winner-of-an-array-game/

// Runtime: 196 ms, faster than 96.92% of C++ online submissions for Find the Winner of an Array Game.
// Memory Usage: 63.5 MB, less than 5.42% of C++ online submissions for Find the Winner of an Array Game.

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans = max(arr[0], arr[1]);
        int cnt = 1;
        for (int i = 2; i < arr.size() && cnt < k; ++i) {
            if (ans > arr[i]) ++cnt;
            else ans = arr[i], cnt = 1;
        }
        return ans;
    }
};