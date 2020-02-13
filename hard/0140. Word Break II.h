// 140. Word Break II

// Time Limit Exceeded
// 31 / 39 test cases passed.
/*class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return {};

        set<int> lens;
        for (const string& word : wordDict)
            lens.insert(word.length());
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<string> ans;
        string sentence;
        f(s, words, lens, 0, sentence, ans);
        return ans;
    }

    void f(const string& s,
        const unordered_set<string>& words,
        const set<int>& lens,
        int begin,
        string& sentence,
        vector<string>& ans) {

        if (begin == s.length()) {
            ans.push_back(sentence);
            return;
        }

        int sl = sentence.length();
        for (int len : lens) {
            if (begin + len > s.length())
                break;

            string word(s.substr(begin, len));
            if (words.count(word) == 0) continue;

            if (sl > 0) sentence.append(" ");
            sentence.append(word);
            f(s, words, lens, begin + len, sentence, ans);
            sentence.erase(sl, (sl > 0 ? 1 : 0) + len);
        }
    }
};*/

// Time Limit Exceeded
/*class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return {};
        
        set<int> lens;
        for (const string& word : wordDict) 
            lens.insert(word.length());
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        unordered_map<int, vector<string>> dp;
        dp.insert({0, vector<string>()});
        
        int start = 0;
        for (int l = 1; l <= s.length(); ++l) {
            for (int len : lens) {
                if (len > l) break;
                
                auto pre_len = l - len;
                auto it = dp.find(pre_len);
                if (it == dp.end()) continue;
                
                string word(s.substr(pre_len, len));
                if (words.count(word) == 0) continue;
                
                if (it->second.empty()) {
                    dp[l].emplace_back(word);
                    continue;
                }
                
                for (const string& pre_str : it->second) {
                    dp[l].emplace_back(pre_str + " " + word);
                }
            }
        }
        
        return dp[s.length()];
    }
};*/