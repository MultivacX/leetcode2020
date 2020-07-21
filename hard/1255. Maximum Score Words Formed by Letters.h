// 1255. Maximum Score Words Formed by Letters
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// Runtime: 12 ms, faster than 76.16% of C++ online submissions for Maximum Score Words Formed by Letters.
// Memory Usage: 9.8 MB, less than 81.54% of C++ online submissions for Maximum Score Words Formed by Letters.

class Solution {
    vector<int> letters_ = vector<int>(26, 0);
    
    int get_score(const string& word, const vector<int>& score) {
        int ans = 0;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (letters_[idx] <= 0) {
                for (int j = i - 1; j >= 0; --j) 
                     ++letters_[word[j] - 'a'];
                ans = -1;
                break;
            } else {
                --letters_[idx];
                ans += score[idx];
            }
        }
        return ans;
    }
    
    void reset(const string& word) {
        for (char c : word) 
            ++letters_[c - 'a'];
    }
    
    int get_scores(const vector<string>& words, const vector<int>& score, int idx) {
        if (idx >= words.size()) return 0;
        
        int ans = 0;
        for (int i = idx; i < words.size(); ++i) {
            int s = get_score(words[i], score);
            if (s < 0) continue;
            ans = max(ans, s + get_scores(words, score, i + 1));
            reset(words[i]);
        }
        return ans;
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char c : letters) ++letters_[c - 'a'];
        
        int ans = 0;
        for (int i = 0; i < words.size(); ++i)
            ans = max(ans, get_scores(words, score, i));
        return ans;
    }
};