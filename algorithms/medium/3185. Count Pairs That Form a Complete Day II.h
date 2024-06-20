// 3185. Count Pairs That Form a Complete Day II
// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;

        /* // TLE
        int maxv = hours[0];
        unordered_map<int, int> h2k;
        int n = hours.size();
        for (int i = 0; i < n; ++i) {
            int v = 24 - hours[i] % 24;
            while (v <= maxv) {
                if (h2k.count(v))
                    res += h2k[v];
                v += 24;
            }

            maxv = max(maxv, hours[i]);
            ++h2k[hours[i]];
        }*/

        
        array<int, 24> h2k;
        for (int h : hours) {
            ++h2k[(24 - h % 24) % 24];
        }

        int i = 0;
        if (h2k[i]) res += (long long)h2k[i] * (h2k[i] - 1) / 2;
        
        i = 12;
        if (h2k[i]) res += (long long)h2k[i] * (h2k[i] - 1) / 2;
        
        for (i = 1; i < 12; ++i) {
            res += (long long)h2k[i] * h2k[24 - i];
        }


        return res;
    }
};