// 2007. Find Original Array From Doubled Array
// https://leetcode.com/problems/find-original-array-from-doubled-array/

// Runtime: 459 ms, faster than 75.18% of C++ online submissions for Find Original Array From Doubled Array.
// Memory Usage: 144 MB, less than 63.98% of C++ online submissions for Find Original Array From Doubled Array.

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() & 1)
            return {};

        map<int, int> m;
        for (int i : changed)
            ++m[i];

        vector<int> ans;
        while (!m.empty())
        {
            auto l = m.begin();
            int lv = l->first;
            // cout << l->first << ", " << l->second << endl;
            if (--l->second == 0)
                m.erase(l);

            int dlv = lv * 2;
            auto dl = m.find(dlv);
            if (dl == m.end())
                return {};
            // cout << dl->first << ", " << dl->second << endl;
            if (--dl->second == 0)
                m.erase(dl);
            ans.push_back(lv);

            if (m.empty())
                break;

            auto r = m.end();
            --r;
            int rv = r->first;
            if (rv & 1)
                return {};
            // cout << r->first << ", " << r->second << endl;
            if (--r->second == 0)
                m.erase(r);

            int hrv = rv >> 1;
            auto hr = m.find(hrv);
            if (hr == m.end())
                return {};
            // cout << hr->first << ", " << hr->second << endl;
            if (--hr->second == 0)
                m.erase(hr);
            ans.push_back(hrv);
        }
        return ans;
    }
};