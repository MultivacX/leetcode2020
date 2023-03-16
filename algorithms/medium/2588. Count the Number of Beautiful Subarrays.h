class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, long long> cnt;
        cnt[0] = 1;
        int i = 0;
        for (int j : nums) {
            i ^= j;
            res += cnt[i];
            ++cnt[i];
        }
        return res;
    }
};