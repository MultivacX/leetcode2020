// 243. Shortest Word Distance
// https://leetcode.com/problems/shortest-word-distance/

// Runtime: 12 ms, faster than 95.79% of C++ online submissions for Shortest Word Distance.
// Memory Usage: 12 MB, less than 60.71% of C++ online submissions for Shortest Word Distance.
    
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -words.size();
        int j = i * 2;
        int ans = words.size() * 2;
        for (int k = 0; k < words.size(); ++k) {
            if (words[k] == word1) {
                i = k;
                ans = min(ans, abs(i - j));
            } else if (words[k] == word2) {
                j = k;
                ans = min(ans, abs(i - j));
            }
        }
        return ans;
    }
};