// 740. Delete and Earn

// Runtime: 20 ms, faster than 10.40% of C++ online submissions for Delete and Earn.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Delete and Earn.

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int p = 0;
        int q = 0;
        int pn = 0;
        int qn = 0;
        int i = 0;
        while (i < nums.size()) {
            int cnt = 0;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] == nums[i]) ++cnt;    
            }
            
            int points = cnt * nums[i];
            
            if (pn == nums[i] - 1) {
                // qn < pn = in - 1, in
                if (p < q) {
                    p = q;
                    pn = qn;
                }
                q += points;
                qn = nums[i];
            } else if (qn == nums[i] - 1) {
                // pn < qn = in - 1, in
                if (q < p) {
                    q = p;
                    qn = pn;
                }
                p += points;
                pn = nums[i];
            } else if (p < q) {
                p = q;
                pn = qn;
                q += points;
                qn = nums[i];
            } else if (q < p) {
                q = p;
                qn = pn;
                p += points;
                pn = nums[i];
            } else {
                p += points;
                pn = nums[i];
            }
            
            i += cnt;
        }
        return max(p, q);
    }
};