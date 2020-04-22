// 954. Array of Doubled Pairs

// Runtime: 128 ms, faster than 61.72% of C++ online submissions for Array of Doubled Pairs.
// Memory Usage: 12.4 MB, less than 100.00% of C++ online submissions for Array of Doubled Pairs.

// Runtime: O(N * log(N)).
// Memory: O(N).

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> positives;
        map<int64_t, int> negatives;
        int ps = 0;
        int ns = 0;
        int zeros = 0;
        for (int i : A) {
            if (i > 0) ++positives[i], ++ps;
            else if (i < 0) ++negatives[-1 * (int64_t)i], ++ns;
            else ++zeros;
        }
        
        // for (auto& it : positives) cout << it.first << ", " << it.second << endl; 
        // for (auto& it : negatives) cout << it.first << ", " << it.second << endl; 
        
        if (ps & 1) return false;
        if (ns & 1) return false;
        if (zeros & 1) return false;
        
        for (auto& it : positives) {
            if (it.second == 0) continue;
            auto next = positives.find(2 * it.first);
            // cout << it.first << ", " << it.second << endl; 
            // if (next != positives.end()) cout << "  " << next->first << ", " << next->second << endl; 
            if (next == positives.end() || it.second > next->second) return false;
            next->second -= it.second;
        }
        
        for (auto& it : negatives) {
            if (it.second == 0) continue;
            auto next = negatives.find(2 * it.first);
            // cout << it.first << ", " << it.second << endl; 
            // if (next != negatives.end()) cout << "  " << next->first << ", " << next->second << endl; 
            if (next == negatives.end() || it.second > next->second) return false;
            next->second -= it.second;
        }
        
        return true;
    }
};