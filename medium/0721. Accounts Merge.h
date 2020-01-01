// 721. Accounts Merge

// Runtime: 136 ms, faster than 61.82% of C++ online submissions for Accounts Merge.
// Memory Usage: 39.5 MB, less than 47.06% of C++ online submissions for Accounts Merge.

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> emails;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                emails[accounts[i][j]].push_back(i);
            }
        }
        
        unordered_set<int> visited;
        for (int i = 0; i < accounts.size(); ++i) {
            
            unordered_set<string> s;
            f(accounts, i, emails, s, visited);
            if (s.empty()) continue;
            
            vector<string> account{accounts[i][0]};
            account.insert(account.end(), s.begin(), s.end());
            sort(account.begin() + 1, account.end());
            ans.push_back(account);
        }
        return ans;
    }
    
    void f(vector<vector<string>>& accounts, int index, unordered_map<string, vector<int>>& emails, unordered_set<string>& s, unordered_set<int>& visited) {
        if (visited.count(index)) return;
        visited.insert(index);
        
        for (int j = 1; j < accounts[index].size(); ++j) {
            const auto& email = accounts[index][j];
            s.insert(email);
            if (emails.count(email) == 0) continue;
            auto indeies(emails[email]);
            emails.erase(email);
            for (auto i : indeies) {
                f(accounts, i, emails, s, visited);
            }
        }
    }
};