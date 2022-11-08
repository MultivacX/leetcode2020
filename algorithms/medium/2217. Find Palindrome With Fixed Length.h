// 2217. Find Palindrome With Fixed Length
// https://leetcode.com/problems/find-palindrome-with-fixed-length/

// Runtime: 514 ms, faster than 25.62% of C++ online submissions for Find Palindrome With Fixed Length.
// Memory Usage: 50.1 MB, less than 85.12% of C++ online submissions for Find Palindrome With Fixed Length.

class Solution
{
public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        long long odd = intLength & 1;
        long long half = (intLength >> 1) + odd;
        long long base = 10;
        long long start = pow(base, (long long)half - 1);
        long long end = pow(base, (long long)intLength);

        vector<long long> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i)
        {
            long long target = start + queries[i] - 1;
            string s(to_string(target));
            string t(s);
            if (odd)
                s.pop_back();
            reverse(s.begin(), s.end());
            t += s;
            if (t.length() > intLength)
                continue;
            // cout << t << ' ';
            target = stoll(t);
            if (target >= end)
                continue;
            res[i] = target;
        }
        // cout << endl;
        return res;
    }
};