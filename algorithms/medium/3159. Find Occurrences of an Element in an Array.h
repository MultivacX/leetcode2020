// 3159. Find Occurrences of an Element in an Array

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> cnt{0};
        for (int i = 0; i < nums.size(); ++i) 
            if (nums[i] == x)
                cnt.push_back(i);

        vector<int> res;
        for (int q : queries) 
            res.push_back(q < cnt.size() ? cnt[q] : -1);
        return res;
    }
};