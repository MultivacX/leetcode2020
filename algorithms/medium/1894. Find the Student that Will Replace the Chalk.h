// 1894. Find the Student that Will Replace the Chalk
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

// Runtime: 108 ms, faster than 100.00% of C++ online submissions for Find the Student that Will Replace the Chalk.
// Memory Usage: 81.3 MB, less than 25.00% of C++ online submissions for Find the Student that Will Replace the Chalk.
    
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int n = chalk.size();
        vector<uint64_t> prefix(n);
        prefix[0] = chalk[0];
        for (int i = 1; i < n; ++i) 
            prefix[i] = prefix[i - 1] + chalk[i];
        
        while (k >= prefix[n - 1])
            k = k % prefix[n - 1];
        return upper_bound(begin(prefix), end(prefix), (uint64_t)k) - begin(prefix);
    }
};