// 809. Expressive Words
// https://leetcode.com/problems/expressive-words/

// Runtime: 20 ms, faster than 21.50% of C++ online submissions for Expressive Words.
// Memory Usage: 9.6 MB, less than 7.72% of C++ online submissions for Expressive Words.

class Solution {
    vector<array<int, 2>> count(const string& s) {
        vector<array<int, 2>> cnt;
        for (const auto& c : s) 
            if (cnt.empty() || cnt.back()[0] != c) cnt.push_back(array<int, 2>{c, 1});
            else ++cnt.back()[1];
        return cnt;
    }
    
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        const auto s = count(S);
        for (auto& W : words) {
            const int M = S.length();
            const int N = W.length();
            if (M < N) continue;
            
            auto w = count(W);
            if (s.size() != w.size()) continue;
            
            int i = 0; 
            while (i < s.size() && s[i][0] == w[i][0] && s[i][1] >= w[i][1]) {
                if (s[i][1] > w[i][1] && s[i][1] < 3) 
                    break;
                ++i;
            }
            if (i == s.size()) ++ans;
        }
        return ans;
    }
};


class Solution {
    vector<pair<char, int>> getGroups(const string& s) {
        vector<pair<char, int>> ans;
        for (int i = 0; i < s.length(); ++i) 
            if (i > 0 && s[i] == ans.back().first) ++ans.back().second;
            else ans.push_back({s[i], 1});
        return ans;
    }
    
    bool compare(const vector<pair<char, int>>& a, const vector<pair<char, int>>& b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) 
            if (a[i].first != b[i].first) return false;
            else if (a[i].second < b[i].second) return false;
            else if (a[i].second > b[i].second && a[i].second < 3) return false;
        return true;
    }
    
public:
    int expressiveWords(string S, vector<string>& words) {
        auto a = getGroups(S);
        int ans = 0;
        for (const string& w : words) {
            auto b = getGroups(w);
            if (compare(a, b)) ++ans;
        }
        return ans;
    }
};