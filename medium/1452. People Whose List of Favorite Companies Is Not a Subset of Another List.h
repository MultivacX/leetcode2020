// 1452. People Whose List of Favorite Companies Is Not a Subset of Another List
// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

// Runtime: 276 ms, faster than 95.33% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.
// Memory Usage: 53.8 MB, less than 63.08% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.
    
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        const int N = favoriteCompanies.size();
        unordered_map<string, int> companies;
        vector<vector<uint64_t>> fids(N);
        for (int i = 0, company_id = 0; i < N; ++i) {
            auto& ids = fids[i];
            for (const auto& c : favoriteCompanies[i]) {
                if (!companies.count(c)) {
                    companies.insert({c, company_id++});
                }
                int id = companies[c];
                int n = id / 64 + 1;
                int b = id % 64;
                if (ids.size() < n) ids.resize(n);
                ids[n - 1] |= (uint64_t)1 << b;
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            const int M = fids[i].size();
            bool isSubset = false;
            for (int j = 0; j < N && !isSubset; ++j) {
                if (i == j || M > fids[j].size()) continue;
                int k = 0;
                for (; k < M; ++k) 
                    if ((fids[i][k] & fids[j][k]) != fids[i][k])
                        break;
                if (k == M) isSubset = true;
            }
            if (!isSubset) ans.push_back(i);
        }
        
        // for (auto& s : fids) {
        //     for (auto id : s) cout << bitset<64>(id) << " ";
        //     cout << endl;
        // }
        return ans;
    }
};