// 1105. Filling Bookcase Shelves
// https://leetcode.com/problems/filling-bookcase-shelves/

// TLE
class Solution {
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
};