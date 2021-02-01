// 1487. Making File Names Unique
// https://leetcode.com/problems/making-file-names-unique/

// Runtime: 1332 ms, faster than 12.29% of C++ online submissions for Making File Names Unique.
// Memory Usage: 83.7 MB, less than 100.00% of C++ online submissions for Making File Names Unique.

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        const int N = names.size();
        vector<string> ans(N);
        unordered_map<string, set<int>> m;
        for (int i = 0; i < N; ++i) {
            const string& key = names[i];
            // cout << key << ": " << endl;
            if (!m.count(key) || !m[key].count(0)) {
                m[key].insert(0);
                ans[i] = key;
                
                if (key.back() != ')') continue;
                int i = key.length() - 2;
                while (i >= 0 && key[i] != '(') {
                    if (!isdigit(key[i])) i = 0;
                    --i;
                }
                if (i < 0) continue;
                int k = stoi(key.substr(i + 1, key.length() - i - 2));
                if (k == 0) continue;
                m[key.substr(0, i)].insert(k);
                // cout << "    " << key.substr(0, i) << "," << k << endl;
            } else {
                int k = 0;
                for (int j : m[key]) {
                    if (j > k) break;
                    ++k;
                }
                m[key].insert(k);
                ans[i] = key + "(" + to_string(k) + ")";
                m[ans[i]].insert(0);
                // cout << "    " << ans[i] << endl;
            }
        }
        return ans;
    }
};