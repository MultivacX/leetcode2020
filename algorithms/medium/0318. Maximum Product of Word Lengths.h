// 318. Maximum Product of Word Lengths

// Runtime: 40 ms, faster than 98.17% of C++ online submissions for Maximum Product of Word Lengths.
// Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Maximum Product of Word Lengths.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int n = words.size();
        if (n <= 1) return 0;
        
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i)
            for (const char& c : words[i])
                nums[i] |= 1 << (c - 'a');
        
        // for (int i = 0; i < n; ++i)
        //     cout << bitset<32>(nums[i]) << endl;
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) 
            for (int j = i + 1; j < n; ++j)
                if ((nums[i] & nums[j]) == 0)
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
        return ans;
    }
};