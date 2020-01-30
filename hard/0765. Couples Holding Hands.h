// 765. Couples Holding Hands

// Runtime: 8 ms, faster than 9.18% of C++ online submissions for Couples Holding Hands.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Couples Holding Hands.

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> m(n, 0);
        for (int i = 0; i < n; ++i)
            m[row[i]] = i;
        
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int vi = row[i] + (row[i] % 2 == 0 ? 1 : -1);
            if (vi == row[i + 1]) 
                continue;
                        
            int vj = row[i + 1];
                    
            int ii = i + 1;
            int ij = m[vi];

            swap(row[ii], row[ij]);
            swap(m[vi], m[vj]);
            
            ++ans;
        }
        // for (int i = 0; i < n; i += 2) cout << row[i] << ", " << row[i + 1] << endl;
        return ans;
    }
};