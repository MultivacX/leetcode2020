// 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// Runtime: 20 ms, faster than 33.39% of C++ online submissions for Sort Array by Increasing Frequency.
// Memory Usage: 13.5 MB, less than 5.23% of C++ online submissions for Sort Array by Increasing Frequency.
    
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<vector<int>> arr(201, vector<int>{2000, 2000});
        for (int i = 0; i < nums.size(); ++i) {
            int j = 100 + nums[i];
            if (arr[j][0] == 2000) 
                arr[j][0] = 0;
            ++arr[j][0];
            arr[j][1] = -nums[i];
        }
        sort(begin(arr), end(arr));
        vector<int> ans;
        for (const auto& v : arr) {
            if (v[1] == 2000) break;
            for (int i = 0; i < v[0]; ++i)
                ans.push_back(-v[1]);
        }
        return ans;
    }
};