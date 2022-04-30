// 1980. Find Unique Binary String
// https://leetcode.com/problems/find-unique-binary-string/

// Runtime: 4 ms, faster than 70.80% of C++ online submissions for Find Unique Binary String.
// Memory Usage: 10.3 MB, less than 50.57% of C++ online submissions for Find Unique Binary String.

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        const int n = nums.size();
        vector<int> v(n + 1);
        for (int i = 0; i <= n; ++i)
            v[i] = i;

        for (const auto &s : nums)
        {
            int k = stoi(s, 0, 2);
            int i = 0;
            while (i < v.size())
            {
                if (v[i] == k)
                {
                    v[i] = v.back();
                    v.pop_back();
                    break;
                }
                ++i;
            }
        }

        string res(bitset<16>(v[0]).to_string());
        if (res.length() > n)
            return res.substr(res.length() - n);
        return res;
    }
};