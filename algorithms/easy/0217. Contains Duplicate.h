// 217. Contains Duplicate

// Runtime: 40 ms, faster than 66.99% of C++ online submissions for Contains Duplicate.
// Memory Usage: 16.5 MB, less than 70.33% of C++ online submissions for Contains Duplicate.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums)
            if (s.count(i)) return true;
            else s.insert(i);
        return false;
    }
};