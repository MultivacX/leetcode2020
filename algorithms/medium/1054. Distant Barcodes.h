// 1054. Distant Barcodes

// Runtime: 232 ms, faster than 81.53% of C++ online submissions for Distant Barcodes.
// Memory Usage: 50.6 MB, less than 100.00% of C++ online submissions for Distant Barcodes.

// Time Complexity: O(size(barcodes) + size(barcodes) * lg(size(c2b))).
// Space Complexity: O(size(barcodes)).

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // {barcode, count}
        unordered_map<int, int> b2c;
        for (int b : barcodes) ++b2c[b];
        
        // {count, {barcode}}
        map<int, vector<int>> c2b;
        for (auto kv : b2c) c2b[kv.second].emplace_back(kv.first);
        
        const int ROWS = c2b.rbegin()->first;
        vector<vector<int>> v(ROWS);
        int row = 0;
        for (auto it = c2b.rbegin(); it != c2b.rend(); ++it) {
            for (int barcode : it->second) {
                while (b2c[barcode]--) {
                    v[row++].emplace_back(barcode);
                    if (row >= ROWS) row = 0;
                }
            }
        }
        
        // for (const auto& row : v) {
        //     for (int b : row) {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<int> ans;
        for (const auto& row : v) ans.insert(end(ans), begin(row), end(row));
        return ans;
    }
};