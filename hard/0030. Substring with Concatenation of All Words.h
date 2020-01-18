// 30. Substring with Concatenation of All Words

// Runtime: 20 ms, faster than 98.54% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 13.8 MB, less than 86.96% of C++ online submissions for Substring with Concatenation of All Words.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        
        int sl = s.length();
        int wl = words[0].length();
        int cnt = words.size();
        int len = wl * cnt;
        if (sl < len) return {};
        
        vector<int> ans;
        
        unordered_map<string, int> m;
        for (auto w : words) ++m[w];
        
        for (int i = 0; i < wl; ++i) {
            deque<string> q; 
            unordered_map<string, int> tmp;
            int j = i;
            while (len - wl * q.size() <= sl - j) {
                string word(s.substr(j, wl));
                if (m.count(word) == 0) {
                    tmp.clear();
                    q.clear();
                } else if (tmp[word] < m[word]) {
                    ++tmp[word];
                    q.push_back(word);
                    if (q.size() == cnt) {
                        ans.push_back(j + wl - len);
                        --tmp[q.front()];
                        q.pop_front();
                    }
                } else {
                    ++tmp[word];
                    q.push_back(word);
                    
                    while (!q.empty() && q.front() != word) {
                        --tmp[q.front()];
                        q.pop_front();   
                    }
                    if (!q.empty()) {
                        --tmp[q.front()];
                        q.pop_front();
                    }
                }
                
                j += wl;
            }
        }
        
        return ans;
    }
};