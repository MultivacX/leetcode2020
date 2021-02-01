// 1105. Filling Bookcase Shelves
// https://leetcode.com/problems/filling-bookcase-shelves/

// Runtime: 8 ms, faster than 90.89% of C++ online submissions for Filling Bookcase Shelves.
// Memory Usage: 8.6 MB, less than 40.89% of C++ online submissions for Filling Bookcase Shelves.
    
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        const int N = books.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = books[0][1];
        for (int i = 1; i < N; ++i) {
            int w = books[i][0];
            int h = books[i][1];
            dp[i] = dp[i - 1] + h;

            int j = i - 1;
            while (j >= 0) {
                // put books[j, i] in last row
                w += books[j][0];
                if (w > shelf_width) break;
                h = max(h, books[j][1]);
                dp[i] = min(dp[i], h + (j > 0 ? dp[j - 1] : 0));
                --j;
            }
        }
        return dp.back();
    }
};

// TLE
/*class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // w, t, b 
        // i_w <= W - w & i_h <= b - t : add
        // i_w > W - w             : new 
        //                         : add or new
        const int N = books.size();
        int w = books[0][0];
        int t = 0;
        int b = books[0][1];
        vector<array<int, 3>> v{{books[0][0], 0, books[0][1]}};
        for (int i = 1; i < N; ++i) {
            int i_w = books[i][0];
            int i_h = books[i][1];
            vector<array<int, 3>> tmp;
            for (auto& a : v) {
                int w = a[0], t = a[1], b = a[2];
                if (i_w <= shelf_width - w & i_h <= b - t) tmp.push_back({w + i_w, t, b});
                else if (i_w > shelf_width - w) tmp.push_back({i_w, b, b + i_h});
                else { tmp.push_back({w + i_w, t, max(b, t + i_h)}); tmp.push_back({i_w, b, b + i_h}); }
            }
            v = tmp;
        }
        int ans = INT_MAX;
        for (auto& a : v) if (a[2] < ans) ans = a[2];
        return ans;
    }
};*/