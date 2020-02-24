// 423. Reconstruct Original Digits from English

// Runtime: 88 ms, faster than 5.50% of C++ online submissions for Reconstruct Original Digits from English.
// Memory Usage: 38.1 MB, less than 100.00% of C++ online submissions for Reconstruct Original Digits from English.

class Solution {
public:
    string originalDigits(string s) {
        static const vector<pair<int, string>> nums{
            {0, "zero"},
            {2, "two"},
            {4, "four"},
            {6, "six"},
            {8, "eight"},
            {1, "one"},
            {3, "three"},
            {7, "seven"},
            {5, "five"},
            {9, "nine"},
        };
        vector<int> nums_cnt(26, 0);
        for (auto it : nums)
            for (const char& c : it.second) 
                ++nums_cnt[c - 'a'];
        
        vector<int> cnts(26, 0);
        for (const char& c : s) {
            if (nums_cnt[c - 'a'] == 0)
                return "";
            ++cnts[c - 'a'];
        }
        
        string ans;
        f(nums, s.length(), cnts, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    bool f(const vector<pair<int, string>>& nums, int n, vector<int>& cnts, string& ans) {
        if (n == 0) 
            return true;
        
        for (auto it : nums) {
            int num = it.first;
            for (const char& c : it.second) {
                if (cnts[c - 'a'] == 0) {
                    num = -1;
                    break;
                }
            }
            if (num < 0)
                continue;
            
            cout << it.second << endl;
            for (int j = 0; j < 26; ++j) 
                printf("%c:%d ", j + 'a', cnts[j]);
            cout << endl;
            
            for (const char& c : it.second)
                --cnts[c - 'a'];
            n -= it.second.length();
            ans += ('0' + num);

            if (f(nums, n, cnts, ans))
                return true;

            n += it.second.length();
            ans.pop_back();
            for (const char& c : it.second)
                ++cnts[c - 'a'];
        }
        
        return false;
    }
};