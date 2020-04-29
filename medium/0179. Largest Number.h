// 179. Largest Number

// Runtime: 28 ms, faster than 7.93% of C++ online submissions for Largest Number.
// Memory Usage: 11.2 MB, less than 9.09% of C++ online submissions for Largest Number.

// Time Complexity: O(N*lgN). N is size of nums
// Space Complexity: O(N).

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "0";
        sort(begin(nums), end(nums), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string ans;
        for (int n : nums) ans += to_string(n);
        return ans[0] == '0' ? "0" : ans;
    }
};