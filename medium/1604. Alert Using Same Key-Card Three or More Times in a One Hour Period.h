// 1604. Alert Using Same Key-Card Three or More Times in a One Hour Period
// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

// Runtime: 424 ms, faster than 84.76% of C++ online submissions for Alert Using Same Key-Card Three or More Times in a One Hour Period.
// Memory Usage: 129.2 MB, less than 18.99% of C++ online submissions for Alert Using Same Key-Card Three or More Times in a One Hour Period.
    
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < keyName.size(); ++i) 
            m[keyName[i]].push_back(keyTime[i]);
        vector<string> ans;
        for (auto it : m) {
            const int N = it.second.size();
            if (N < 3) continue;
            sort(begin(it.second), end(it.second));
            for (int i = 0; i + 2 < N; ++i) {
                int h = (it.second[i + 2][0] - it.second[i][0]) * 10 +
                         it.second[i + 2][1] - it.second[i][1];
                int m = (it.second[i + 2][3] - it.second[i][3]) * 10 +
                         it.second[i + 2][4] - it.second[i][4];
                if (h * 60 + m > 60) continue;
                ans.push_back(it.first);
                break;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};