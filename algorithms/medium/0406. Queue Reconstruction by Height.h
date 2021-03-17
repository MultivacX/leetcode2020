// 406. Queue Reconstruction by Height

// Runtime: 280 ms, faster than 5.58% of C++ online submissions for Queue Reconstruction by Height.
// Memory Usage: 13.2 MB, less than 19.05% of C++ online submissions for Queue Reconstruction by Height.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int n = people.size();
        if (n <= 1) return people;
        
        sort(people.begin(), people.end(), [](vector<int>& l, vector<int>& r){
            return l[0] > r[0] || (l[0] == r[0] && l[1] < r[1]);
        });
        for (int i = 1; i < n; ++i) {
            // for (int j = 0; j < i; ++j) cout << "[" << people[j][0] << ", " << people[j][1] << "], ";
            // cout << endl;
            auto cur = people[i];
            people.erase(people.begin() + i);
            people.insert(people.begin() + cur[1], cur);
        }
        // for (int j = 0; j < n; ++j) cout << "[" << people[j][0] << ", " << people[j][1] << "], ";
        // cout << endl;
        return people;
    }
};


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int n = people.size();
        if (n <= 1) return people;
        
        sort(begin(people), end(people), [](const vector<int>& l, const vector<int>& r){
            return l[1] < r[1] || (l[0] < r[0] && l[1] == r[1]);
        });
        
        vector<vector<int>> ans;
        for (const auto& p : people) {
            // cout << '[' << p[0] << ',' << p[1] << ']' << " ";
            if (p[1] == 0) {
                ans.push_back(p);
            } else {
                int i = 0, k = 0;
                while (i < ans.size() && k < p[1]) {
                    if (ans[i][0] >= p[0]) 
                        ++k;
                    ++i;
                }
                while (i < ans.size() && ans[i][0] < p[0]) ++i;
                ans.insert(begin(ans) + i, p);
            }
        }
        return ans;
    }
};