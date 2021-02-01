// 1406. Stone Game III
// https://leetcode.com/problems/stone-game-iii/

// Runtime: 584 ms, faster than 25.44% of C++ online submissions for Stone Game III.
// Memory Usage: 155.9 MB, less than 17.19% of C++ online submissions for Stone Game III.
    
class Solution {
    int takeStones(vector<int>& stoneValue, vector<int>& prefix, vector<int>& memo, int start) {
        if (start >= stoneValue.size()) return 0;
        if (memo[start] > -50000001) return memo[start];
        
        const int end = min(start + 3, (int)stoneValue.size());
        int ans = -50000001;
        for (int i = start, taken = 0, remain = 0; i < end; ++i) {
            taken += stoneValue[i];
            remain = prefix.back() - prefix[i];
            ans = max(ans, taken + remain - takeStones(stoneValue, prefix, memo, i + 1));
            // if (start == 0) cout << taken << ", " << remain << ", " << ans << endl;
        }
        memo[start] = ans;
        return ans;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> prefix(stoneValue);
        for (int i = 1; i < stoneValue.size(); ++i)
            prefix[i] = prefix[i - 1] + stoneValue[i];
        vector<int> memo(stoneValue.size(), -50000001);
        int alice = takeStones(stoneValue, prefix, memo, 0);
        int bob = prefix.back() - alice;
        if (alice == bob) return "Tie";
        return alice > bob ? "Alice" : "Bob";
    }
};