// 245. Shortest Word Distance III
// https://leetcode.com/problems/shortest-word-distance-iii/

// Runtime: 16 ms, faster than 83.33% of C++ online submissions for Shortest Word Distance III.
// Memory Usage: 12.2 MB, less than 90.23% of C++ online submissions for Shortest Word Distance III.
    
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        const int N = words.size();
        int ans = N;
        bool same = word1 == word2;
        for (int i = 0, i1 = -N, i2 = -N; i < N; ++i) {
            if (words[i] == word1) {
                if (same) ans = min(ans, i - i1);
                else ans = min(ans, i - i2);   
                i1 = i;
            } else if (!same && words[i] == word2) {
                ans = min(ans, i - i1);
                i2 = i;
            } 
        }
        return ans;
    }
};