// 140. Word Break II

// Runtime: 4 ms, faster than 99.68% of C++ online submissions for Word Break II.
// Memory Usage: 12.3 MB, less than 87.88% of C++ online submissions for Word Break II.

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return {};

        unordered_set<int> lens;
        for (const string& word : wordDict)
            lens.insert(word.length());
        
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> m;
        
        return wordBreak(s, lens, words, m);
    }

    vector<string> wordBreak(string s, 
                              const unordered_set<int>& lens,
                              const unordered_set<string>& words,
                              unordered_map<string, vector<string>>& m) {
        auto it = m.find(s);
        if (it != m.end()) return m[s];
        
        vector<string> ans;
        for (int len : lens) {
            if (len > s.length()) continue;
            
            auto word = s.substr(0, len);
            if (words.count(word) == 0) continue;
            // cout << s << ": " << word << " >> " << s.substr(len) << endl;
            if (len == s.length()) {
                ans.emplace_back(word);
            } else {
                for (auto ss : wordBreak(s.substr(len), lens, words, m)) {
                    // cout << "    " << s << endl;
                    if (ss.empty()) ans.emplace_back(word);   
                    else ans.emplace_back(word + " " + ss);   
                }   
            }
        }
         m[s] = ans;
        return m[s];
    }
};

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


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const int n = s.length();
        int min_len = n, max_len = 0;
        for (const auto& w : wordDict) {
            if (min_len > w.length()) min_len = w.length();
            if (max_len < w.length()) max_len = w.length();
        }
        if (n < min_len) return {};
        if (n == min_len) return find(begin(wordDict), end(wordDict), s) != end(wordDict) ?
            vector<string>{s} : vector<string>();
        
        unordered_set<string> words(begin(wordDict), end(wordDict));
        vector<bool> dp(n + 1);
        dp[0] = true;
        
        unordered_map<int, vector<string>> m;
        
        for (int i = 1; i <= n; ++i) {
            for (int l = min_len, j = i - min_len; l <= max_len && j >= 0; ++l, --j) {
                if (!dp[j]) continue;
                string str(s.substr(j, l));
                if (!words.count(str)) continue;
                
                dp[i] = true;
                
                if (j == 0) {
                    m[i].push_back(str);
                } else {
                    for (const string& pre : m[j]) 
                        m[i].push_back(pre + " " + str);
                }
            }
        }
        
        return m[n];
    }
};