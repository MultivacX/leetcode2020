// 179. Largest Number

// Runtime: 28 ms, faster than 7.93% of C++ online submissions for Largest Number.
// Memory Usage: 11.2 MB, less than 9.09% of C++ online submissions for Largest Number.

// Time Complexity: O(N*lgN). N is size of nums.
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


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            strs[i] = to_string(nums[i]);
        sort(begin(strs), end(strs), [](const string& l, const string& r){
            return l + r > r + l;
        });
        
        string ans;
        for (const auto& s : strs) ans += s;
        
        if (ans[0] == '0') return "0";
        return ans;
    }
};