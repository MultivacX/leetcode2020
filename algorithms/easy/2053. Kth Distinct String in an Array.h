// 2053. Kth Distinct String in an Array
// https://leetcode.com/problems/kth-distinct-string-in-an-array/

// Runtime: 27 ms, faster than 61.08% of C++ online submissions for Kth Distinct String in an Array.
// Memory Usage: 14.8 MB, less than 25.69% of C++ online submissions for Kth Distinct String in an Array.

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> m;
        for (const auto &s : arr)
            ++m[s];

        for (const auto &s : arr)
            if (m[s] == 1 && --k == 0)
                return s;
        return "";
    }
};