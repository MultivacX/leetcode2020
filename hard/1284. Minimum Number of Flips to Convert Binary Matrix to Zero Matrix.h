// 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

// Runtime: 416 ms, faster than 5.23% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.
// Memory Usage: 16.1 MB, less than 5.85% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.

class Solution {
    unordered_map<int, int> pathes;
    unordered_set<int> visited;
    int ans;
    int M;
    int N;
    int K;
    int num;

    // void print() {
    //     for (int i = 0, k = 0; i < M; ++i) {
    //         for (int j = 0; j < N; ++j, ++k) 
    //             cout << ((num & (1 << k)) ? 1 : 0);    
    //         cout << endl;
    //     }
    // }
    
    void flip(int k) {
        int i = k / N;
        int j = k % N;
        num ^= (1 << k);
        if (i > 0)     { k = (i - 1) * N + j; num ^= (1 << k); }
        if (i + 1 < M) { k = (i + 1) * N + j; num ^= (1 << k); }
        if (j > 0)     { k = i * N + j - 1;   num ^= (1 << k); }
        if (j + 1 < N) { k = i * N + j + 1;   num ^= (1 << k); }
    }
    
    void find(int steps) {
        if (num == 0) {
            if (ans > steps)
                ans = steps;
            return;
        }

        if (pathes.count(num) && pathes[num] <= steps) return;
        pathes[num] = steps;
        
        if (visited.count(num)) return;
        visited.insert(num);
        int cur = num;
        for (int k = 0; k < K; ++k) {
            flip(k);
            // print();
            find(steps + 1);
            num = cur;
        }
        visited.erase(num);
    }
    
public:
    int minFlips(vector<vector<int>>& mat) {
        ans = INT_MAX;
        M = mat.size();
        N = mat[0].size();
        K = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j, ++K) {
                num |= mat[i][j] << K;
            }
        }
        find(0);
        return ans == INT_MAX ? -1 : ans;
    }
};