// 599. Minimum Index Sum of Two Lists
// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

// Runtime: 176 ms, faster than 33.44% of C++ online submissions for Minimum Index Sum of Two Lists.
// Memory Usage: 51.1 MB, less than 5.81% of C++ online submissions for Minimum Index Sum of Two Lists.

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < list1.size(); ++i) 
            m[list1[i]] = vector<int>{i, 2000};
        for (int i = 0; i < list2.size(); ++i) {
            auto it = m.find(list2[i]);
            if (it == m.end()) m[list2[i]] = vector<int>{2000, i};
            else it->second[1] = i;
        }
        
        map<int, vector<string>> n;
        for (auto it : m) {
            // cout << it.first << ": " << it.second[0] << " + " << it.second[1] << endl; 
            int sum = it.second[0] + it.second[1];
            if (sum >= 2000) continue;
            if (n.empty() || sum == n.begin()->first) 
                n[sum].push_back(it.first);
            else if (sum < n.begin()->first) {
                n.clear();
                n[sum].push_back(it.first);
            }
        }
        return n.begin()->second;
    }
};