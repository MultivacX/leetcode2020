// 2433. Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int v = pref[0];
        for (int i = 1; i < pref.size(); ++i)
        {
            int t = pref[i];
            pref[i] ^= v;
            v = t;
        }
        return pref;
    }
};