// 2442. Count Number of Distinct Integers After Reverse Operations
// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

// Runtime: 867 ms, faster than 53.49% of C++ online submissions for Count Number of Distinct Integers After Reverse Operations.
// Memory Usage: 106.6 MB, less than 88.59% of C++ online submissions for Count Number of Distinct Integers After Reverse Operations.

class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i : nums)
            s.insert(i);

        for (int i : nums)
        {
            // cout << i;
            int j = 0;
            while (i)
            {
                j = j * 10 + i % 10;
                i /= 10;
            }
            // cout << ' ' << j << endl;
            s.insert(j);
        }
        return s.size();
    }
};