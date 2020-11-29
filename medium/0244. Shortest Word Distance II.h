// 244. Shortest Word Distance II
// https://leetcode.com/problems/shortest-word-distance-ii/

// Runtime: 84 ms, faster than 7.33% of C++ online submissions for Shortest Word Distance II.
// Memory Usage: 19.7 MB, less than 96.00% of C++ online submissions for Shortest Word Distance II.
    
class WordDistance {
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            m[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        const auto& v1 = m[word1];
        const auto& v2 = m[word2];
        const int L1 = v1.size();
        const int L2 = v2.size();
        int i1 = 0;
        int i2 = 0;
        int ans = abs(v1[i1] - v2[i2]);
        while (i1 < L1 || i2 < L2) {
            if (i1 < L1 && i2 < L2) v1[i1] < v2[i2] ? ++i1 : ++i2;
            else if (i1 < L1) ++i1;
            else ++i2;
            
            int d1 = i1 < L1 ? i1 : L1 - 1;
            int d2 = i2 < L2 ? i2 : L2 - 1;
            ans = min(ans, abs(v1[d1] - v2[d2]));
        }
        return ans;
    }

    // optim
    /*int shortest(string word1, string word2) {
        int i1 = 0;
        int i2 = 0;
        int ans = INT_MAX;
        while (i1 < m[word1].size() && i2 < m[word2].size()) {
            ans = min(ans, abs(m[word1][i1] - m[word2][i2]));
            m[word1][i1] < m[word2][i2] ? ++i1 : ++i2;
        }
    }*/
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */