// 683. K Empty Slots
// https://leetcode.com/problems/k-empty-slots/

// Runtime: 352 ms, faster than 46.15% of C++ online submissions for K Empty Slots.
// Memory Usage: 91.1 MB, less than 34.62% of C++ online submissions for K Empty Slots.
    
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        const int N = bulbs.size();
        set<int> s;
        for (int i = 0; i < N; ++i) {
            auto it = s.insert(bulbs[i]).first;
            
            auto r = it;
            if (++r != s.end() && *r - bulbs[i] == k + 1) 
                return i + 1;
            
            auto l = it;
            if (l != s.begin() && bulbs[i] - *(--l) == k + 1)
                return i + 1;
        }
        return -1;
    }
};