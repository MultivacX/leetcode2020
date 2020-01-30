// 354. Russian Doll Envelopes

class Solution {
public:
    /*int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 1. sort by w
        // sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
        set<vector<int>> s(envelopes.begin(), envelopes.end());
        // for (const auto& k : s) cout << k[0] << ", " << k[1] << endl;
        // 2. count envelope[i] as last envelope
        vector<vector<int>> cnt;
        for (const auto& k : s) {
            auto it = lower_bound(cnt.begin(), cnt.end(), k, [](const vector<int>& a, const vector<int>& b){ 
                return a[0] < b[0]; 
            });
            if (it == cnt.end()) {
                cnt.push_back(k);
            } else if ((*it)[0] == k[0] && (*it)[1] > k[1]) {
                (*it)[1] = k[1];
            }
        }
        return cnt.size();
    }*/
};