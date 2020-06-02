// 330. Patching Array
// https://leetcode.com/problems/patching-array/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<bool> arr(n + 1, false);
        int cnt = 0;
        int max_val = 0;
        
        for (int i : nums) {
            if (!arr[i]) ++cnt;
            max_val = max(max_val, i);
            
            // i + j <= n
            for (int j = min(max_val, n - i); j > 0 && cnt < n; --j) {
                if (!arr[j]) continue;
                int k = i + j;
                if (!arr[k]) ++cnt;
                max_val = max(max_val, k);
                arr[k] = true;
            }
            
            arr[i] = true;
        }
        
        // for (int k = 1; k <= n; ++k) cout << (arr[k] ? k : 0) << " "; cout << endl;
        
        int ans = 0;
        
        for (int i = 1; i <= n && cnt < n; ++i) {
            if (arr[i]) continue;
            max_val = max(max_val, i);
            
            // i + j <= n
            for (int j = min(max_val, n - i); j > 0 && cnt < n; --j) {
                if (!arr[j]) continue;
                int k = i + j;
                if (!arr[k]) ++cnt;
                max_val = max(max_val, k);
                arr[k] = true;
            }
            
            arr[i] = true;
            ++ans;
            
            // cout << i << " ---------- " << endl;
            // for (int k = 1; k <= n; ++k) cout << (arr[k] ? k : 0) << " "; cout << endl;
        }

        return ans;
    }
};