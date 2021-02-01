// 846. Hand of Straights
// https://leetcode.com/problems/hand-of-straights/

// Runtime: 160 ms, faster than 68.08% of C++ online submissions for Hand of Straights.
// Memory Usage: 26.1 MB, less than 69.64% of C++ online submissions for Hand of Straights.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        for (int i : hand) ++m[i];
        
        for (auto& it : m) {
            int cnt = it.second;
            if (cnt == 0) continue;
            
            int val = it.first;
            for (int i = val; i < val + W; ++i) {
                if (m.count(i) == 0 || m[i] < cnt) return false;
                m[i] -= cnt;
            }
        }
        
        for (auto& it : m) if (it.second) return false;
        return true;
    }
};