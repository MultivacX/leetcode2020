// 646. Maximum Length of Pair Chain

// Runtime: 56 ms, faster than 84.81% of C++ online submissions for Maximum Length of Pair Chain.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Maximum Length of Pair Chain.

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        if (n <= 1) return n;
        
        sort(pairs.begin(), pairs.end(), [](vector<int>& left, vector<int>& right){
            return left[0] < right[0] || (left[0] == right[0] && left[1] > right[1]);
        });
        int ans = 1;
        auto& cur = pairs[0];
        // vector<vector<int>> v{pairs[0]};
        for (int i = 1; i < n; ++i) {
            if (cur[1] < pairs[i][0]) {
                // v.push_back(pairs[i]);
                ++ans;
                cur = pairs[i];
            } else if (cur[1] <= pairs[i][1]) {
                continue;
            } else {
                // v.pop_back();
                // v.push_back(pairs[i]);
                cur = pairs[i];
            }
        }
        // return v.size();
        return ans;
    }
};