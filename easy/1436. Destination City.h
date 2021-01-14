// 1436. Destination City
// https://leetcode.com/problems/destination-city/

// Runtime: 12 ms, faster than 99.73% of C++ online submissions for Destination City.
// Memory Usage: 10.7 MB, less than 88.50% of C++ online submissions for Destination City.
    
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> m;
        for (const auto& p : paths) 
            ++m[p[0]], --m[p[1]];
        
        for (auto it : m)
            if (it.second < 0)
                return it.first;
        return "";
    }
};