// 1887. Reduction Operations to Make the Array Elements Equal
// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

// Runtime: 1092 ms, faster than 33.33% of C++ online submissions for Reduction Operations to Make the Array Elements Equal.
// Memory Usage: 146.3 MB, less than 33.33% of C++ online submissions for Reduction Operations to Make the Array Elements Equal.
    
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m.emplace(n, 0);
        
        int i = 0;
        for (auto& it: m) it.second = i++;
            
        int k = 0;
        for (int n : nums) k += m[n];
        return k;
    }
};