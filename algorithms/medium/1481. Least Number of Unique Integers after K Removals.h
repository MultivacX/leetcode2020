// 1481. Least Number of Unique Integers after K Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// Runtime: 300 ms, faster than 97.88% of C++ online submissions for Least Number of Unique Integers after K Removals.
// Memory Usage: 59.8 MB, less than 100.00% of C++ online submissions for Least Number of Unique Integers after K Removals.

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if (k == arr.size()) return 0;
        
        unordered_map<int, int> val_cnt;
        for (int i : arr) ++val_cnt[i];
        int ans = val_cnt.size();
        if (k == 0) return ans;
        
        map<int, int> cnt_uni;
        for (auto it : val_cnt) ++cnt_uni[it.second];
        
        for (auto it = cnt_uni.begin(); k > 0 && it != cnt_uni.end(); ++it) {
            int uni = it->second;
            int cnt = it->first;
            if (k >= uni * cnt) {
                ans -= uni;
                k -= uni * cnt;
            } else {
                ans -= k / cnt;
                break;    
            }
        }
        return ans;
    }
};