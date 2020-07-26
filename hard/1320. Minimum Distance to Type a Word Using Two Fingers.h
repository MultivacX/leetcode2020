// 1320. Minimum Distance to Type a Word Using Two Fingers
// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

class Solution {
    int get_dist(const unordered_map<char, vector<int>>& M, char from, char to) {
        return abs(M.at(from)[0] - M.at(to)[0]) + abs(M.at(from)[1] - M.at(to)[1]);
    }

public:
    int minimumDistance(string word) {
        static const unordered_map<char, vector<int>> MAP{
            {'A', {0, 0}}, {'B', {0, 1}}, {'C', {0, 2}}, {'D', {0, 3}}, {'E', {0, 4}}, {'F', {0, 5}}, 
            {'G', {1, 0}}, {'H', {1, 1}}, {'I', {1, 2}}, {'J', {1, 3}}, {'K', {1, 4}}, {'L', {1, 5}}, 
            {'M', {2, 0}}, {'N', {2, 1}}, {'O', {2, 2}}, {'P', {2, 3}}, {'Q', {2, 4}}, {'R', {2, 5}}, 
            {'S', {3, 0}}, {'T', {3, 1}}, {'U', {3, 2}}, {'V', {3, 3}}, {'W', {3, 4}}, {'X', {3, 5}}, 
            {'Y', {4, 0}}, {'Z', {4, 1}}
        };
        
        const int M = 10 * 300;
        const int N = word.length();
        if (N <= 2) return 0;

        // prefix[i]: distance(from(0), to(i))
        vector<int> prefix(N, 0);
        for (int i = 1; i < N; ++i)
            prefix[i] = prefix[i - 1] + get_dist(MAP, word[i - 1], word[i]);
        
        vector<int> dp(N, M);
        
        int ans = prefix[N - 2];
        for (int i = 0; i < N - 1; ++i) 
            ans = min(ans, prefix[i] + dp[i + 1]);
        return ans;
    }
};