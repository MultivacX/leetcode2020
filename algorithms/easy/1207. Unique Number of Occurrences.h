// 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Number of Occurrences.
// Memory Usage: 8.2 MB, less than 98.70% of C++ online submissions for Unique Number of Occurrences.
    
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i : arr) ++m[i];
        unordered_set<int> s;
        for (auto it : m) 
            if (!s.insert(it.second).second)
                return false;
        return true;
    }
};