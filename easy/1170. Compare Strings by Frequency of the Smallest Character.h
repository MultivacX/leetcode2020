// 1170. Compare Strings by Frequency of the Smallest Character
// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

// Runtime: 16 ms, faster than 91.61% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// Memory Usage: 12 MB, less than 51.89% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](const string& s){
            char t = 'z' + 1;
            int f = 0;
            for (char c : s) {
                if (c < t) { t = c; f = 1; }
                else if (c == t) ++f;
            }
            return f;
        };
        vector<int> freqs(words.size());
        for (int i = 0; i < words.size(); ++i)
            freqs[i] = f(words[i]);
        sort(begin(freqs), end(freqs));
        vector<int> nums(queries.size());
        for (int i = 0; i < queries.size(); ++i) 
            nums[i] = end(freqs) - upper_bound(begin(freqs), end(freqs), f(queries[i]));
        return nums;
    }
};