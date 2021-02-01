// 1202. Smallest String With Swaps

// Runtime: 432 ms, faster than 8.30% of C++ online submissions for Smallest String With Swaps.
// Memory Usage: 65.2 MB, less than 100.00% of C++ online submissions for Smallest String With Swaps.

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int N = s.length();
        
        vector<unordered_set<int>> u(N);
        for (const auto& pair : pairs) {
            u[pair[0]].insert(pair[1]);
            u[pair[1]].insert(pair[0]);
        }
        
        vector<bool> visited(N, false);
        string r(N, ' ');
        for (int i = 0; i < N; ++i) {
            if (visited[i]) 
                continue;
            
            if (u[i].empty()) {
                r[i] = s[i];
                visited[i] = true;
                continue;
            }
            
            vector<int> index;
            string t;
            deque<int> q{i};
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int j = q.front();
                    q.pop_front();
                    
                    if (visited[j]) 
                        continue;
                    
                    visited[j] = true;
                    index.push_back(j);
                    t += s[j];
                    
                    for (int k : u[j]) {
                        if (visited[k]) 
                            continue;
                        
                        q.push_back(k);
                    }   
                }
            }
            
            sort(begin(index), end(index));
            sort(begin(t), end(t));
            // cout << i << ":" << endl << "  ";
            // for (int idx : index) cout << idx << " ";
            // cout << endl << "  ";
            // for (char c : t) cout << c << " ";
            // cout << endl;
            for (int j = 0; j < index.size(); ++j) 
                r[index[j]] = t[j];
        }
        return r;
    }
};