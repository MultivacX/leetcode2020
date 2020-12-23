// 839. Similar String Groups

/*class Solution {
    bool anagram(const string& a, const string& b) {
        const int N = a.length();
        char ca = 0, cb = 0;
        int diff = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] == b[i]) continue;
            if (ca == 0) ca = a[i], cb = b[i];
            else if (ca != b[i] || cb != a[i]) return false;
            if (++diff > 2) return false;
        }
        return diff == 0 || diff == 2;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, int> m;
        for (auto s : strs) ++m[s];
        int ans = 0;
        for (auto i = m.cbegin(); i != m.cend(); ++i) {
            bool found = false;
            auto j = i;
            for (++j; j != m.cend(); ++j) {
                if (anagram(i->first, j->first)) {
                    ++ans;
                    found = true;
                }
            }    
            if (found && i->second > 1) ++ans;
        }
        return ans;
    }
};*/