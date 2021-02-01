// 1131. Maximum of Absolute Value Expression
// https://leetcode.com/problems/maximum-of-absolute-value-expression/

// Runtime: 100 ms, faster than 60.13% of C++ online submissions for Maximum of Absolute Value Expression.
// Memory Usage: 24.9 MB, less than 6.64% of C++ online submissions for Maximum of Absolute Value Expression.

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        const int N = arr1.size();
        int ans = 0;
        // i < j : val = j - i + |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]|        
        // 1. arr1[i] <= arr1[j] and arr2[i] <= arr2[j]
        // 2. arr1[i] <= arr1[j] and arr2[i] >  arr2[j]
        // 3. arr1[i] >  arr1[j] and arr2[i] <= arr2[j]
        // 4. arr1[i] >  arr1[j] and arr2[i] >  arr2[j]
        vector<int> I{0, 0, 0, 0};
        const vector<vector<int>> CUR_D{{ 1,  1}, { 1, -1}, {-1,  1}, {-1, -1}};
        const vector<vector<int>> PRE_D{{-1, -1}, {-1,  1}, { 1, -1}, { 1,  1}};
        for (int j = 1; j < N; ++j) {
            int k = 0;
            int i = I[k];
            if (arr1[i] <= arr1[j] and arr2[i] <= arr2[j]) { 
                int v = j + CUR_D[k][0] * arr1[j] + CUR_D[k][1] * arr2[j]
                       -i + PRE_D[k][0] * arr1[i] + PRE_D[k][1] * arr2[i];
                ans = max(ans, v);
            }
            
            k = 1;
            i = I[k];
            if (arr1[i] <= arr1[j] and arr2[i] > arr2[j]) { 
                int v = j + CUR_D[k][0] * arr1[j] + CUR_D[k][1] * arr2[j]
                       -i + PRE_D[k][0] * arr1[i] + PRE_D[k][1] * arr2[i];
                ans = max(ans, v);
            }
            
            k = 2;
            i = I[k];
            if (arr1[i] > arr1[j] and arr2[i] <= arr2[j]) { 
                int v = j + CUR_D[k][0] * arr1[j] + CUR_D[k][1] * arr2[j]
                       -i + PRE_D[k][0] * arr1[i] + PRE_D[k][1] * arr2[i];
                ans = max(ans, v);
            }
            
            k = 3;
            i = I[k];
            if (arr1[i] > arr1[j] and arr2[i] > arr2[j]) { 
                int v = j + CUR_D[k][0] * arr1[j] + CUR_D[k][1] * arr2[j]
                       -i + PRE_D[k][0] * arr1[i] + PRE_D[k][1] * arr2[i];
                ans = max(ans, v);
            }
            
            for (int k = 0; k < 4; ++k) {
                int i = I[k];
                if (-j + PRE_D[k][0] * arr1[j] + PRE_D[k][1] * arr2[j] > 
                    -i + PRE_D[k][0] * arr1[i] + PRE_D[k][1] * arr2[i]) 
                    I[k] = j;
            }
        }
        return ans;
    }
};