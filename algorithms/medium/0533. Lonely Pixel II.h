// 533. Lonely Pixel II
// https://leetcode.com/problems/lonely-pixel-ii/

// Runtime: 76 ms, faster than 98.18% of C++ online submissions for Lonely Pixel II.
// Memory Usage: 20.8 MB, less than 25.45% of C++ online submissions for Lonely Pixel II.

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        const int R = picture.size();
        const int C = picture[0].size();
        
        vector<bool> rows(R), cols(C);
        for (int i = 0; i < R; ++i) {
            int b = 0;
            for (int j = 0; j < C; ++j) 
                if (picture[i][j] == 'B') ++b;
            if (b != N) continue;
            rows[i] = true;
        }
        for (int j = 0; j < C; ++j) {
            int b = 0;
            for (int i = 0; i < R; ++i)
                if (picture[i][j] == 'B') ++b;
            if (b != N) continue;
            cols[j] = true;
        }
        
        vector<string> keys(R);
        unordered_map<string, int> m;
        for (int i = 0; i < R; ++i) {
            string k;
            k.insert(begin(k), begin(picture[i]), end(picture[i]));
            keys[i] = k;
            ++m[k];
        }

        int ans = 0;
        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < R; ++i) {
                if (picture[i][j] == 'B' && rows[i] && cols[j] && m[keys[i]] == N) {
                    ++ans;
                    // cout << picture[i][j] << i << ", " << j << "  " << keys[i] << endl;
                }
            }
        }
        return ans;
    }
};