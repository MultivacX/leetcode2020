// 1868. Product of Two Run-Length Encoded Arrays
// https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/

// Runtime: 520 ms, faster than 100.00% of C++ online submissions for Product of Two Run-Length Encoded Arrays.
// Memory Usage: 204.5 MB, less than 100.00% of C++ online submissions for Product of Two Run-Length Encoded Arrays.
    
class Solution {
    void update(vector<vector<int>>& ans, int val, int cnt) {
        if (ans.empty() || ans.back()[0] != val) {
            ans.push_back({val, cnt});
        } else {
            ans.back()[1] += cnt;
        }
    }
    
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        const int m = encoded1.size();
        const int n = encoded2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int v1 = encoded1[i][0]; 
            int& k1 = encoded1[i][1];
            int v2 = encoded2[j][0]; 
            int& k2 = encoded2[j][1];
            
            int k = min(k1, k2);
            update(ans, v1 * v2, k);
            k1 -= k; if (k1 == 0) ++i;
            k2 -= k; if (k2 == 0) ++j;
        }
        return ans;
    }
};