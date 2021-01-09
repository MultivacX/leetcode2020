// 1313. Decompress Run-Length Encoded List
// https://leetcode.com/problems/decompress-run-length-encoded-list/

// Runtime: 8 ms, faster than 59.16% of C++ online submissions for Decompress Run-Length Encoded List.
// Memory Usage: 11.1 MB, less than 5.81% of C++ online submissions for Decompress Run-Length Encoded List.
    
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        const int N = nums.size();
        for (int i = 0; 2 * i + 1 < N; ++i) {
            vector<int> sub(nums[2 * i], nums[2 * i + 1]);
            ans.insert(ans.end(), begin(sub), end(sub));
        }
        return ans;
    }
};