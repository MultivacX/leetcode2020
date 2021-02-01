// 611. Valid Triangle Number

// Runtime: 36 ms, faster than 38.51% of C++ online submissions for Valid Triangle Number.
// Memory Usage: 9.2 MB, less than 50.00% of C++ online submissions for Valid Triangle Number.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) continue;
            if (v.empty() || v.back()[0] != nums[i]) v.push_back({nums[i], 1});
            else ++v.back()[1];
        }
        return count(v, 0, 0, 0, 0);
    }
    
    int count(const vector<vector<int>>& v, int begin, int A, int B, int C) {
        int ans = 0;
        const int n = v.size();
        for (int i = begin; i < n && (A == 0 || B == 0 || C == 0); ++i) {
            int val = v[i][0];
            int cnt = v[i][1];
            
            if (cnt >= 3 && A == 0) {
                // A == val, B == val, C == val
                ans += combinations(3, cnt);
            }
            
            if (cnt >= 2) {
                if (A == 0 && i < n - 1) {
                    // A == val, B == val, C == v[j] (j > i && j < n)
                    ans += combinations(2, cnt) * count(v, i + 1, val, val, 0);
                } else if (B == 0 && isTriangle(A, val, val)) {
                    // A != 0, B == val, C == val
                    ans += combinations(2, cnt);
                }
            }
            
            if (A == 0) ans += cnt * count(v, i + 1, val, 0, 0);
            else if (B == 0 && i < n - 1) ans += cnt * count(v, i + 1, A, val, 0);
            else if (C == 0 && isTriangle(A, B, val)) ans += cnt;
        }
        return ans;
    }
    
    int combinations(int m, int n) {
        int N = 1;
        for (int i = n - m + 1; i <= n; ++i)
            N *= i;
        for (int i = 2; i <= m; ++i)
            N /= i;
        return N;
    }
    
    bool isTriangle(int A, int B, int C) {
        if (A == 0 || B == 0 || C == 0) return false;
        return A + B > C && A + C > B && B + C > A;
    }
};