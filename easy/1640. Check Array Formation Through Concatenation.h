// 1640. Check Array Formation Through Concatenation
// https://leetcode.com/problems/check-array-formation-through-concatenation/

// Runtime: 4 ms, faster than 95.56% of C++ online submissions for Check Array Formation Through Concatenation.
// Memory Usage: 10.3 MB, less than 95.52% of C++ online submissions for Check Array Formation Through Concatenation.
    
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> m;
        for (int i = 0; i < pieces.size(); ++i)
            m.emplace(pieces[i][0], i);
        for (int i = 0, j = -1, k = -1; i < arr.size(); ++i) {
            if (j == -1) {
                auto it = m.find(arr[i]);
                if (it == m.end()) return false;
                j = it->second;
                k = 0;
            } else if (arr[i] != pieces[j][k]) {
                return false;
            }
            
            if (++k >= pieces[j].size()) {
                j = -1;
            }
        }
        return true;
    }
};