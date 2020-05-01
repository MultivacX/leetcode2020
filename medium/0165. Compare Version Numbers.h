// 165. Compare Version Numbers

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Compare Version Numbers.

// Time Complexity: O(n1+n2).
// Space Complexity: O(1).

class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.length();
        const int n2 = version2.length();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            int v1 = 0;
            while (i < n1 && version1[i] != '.') 
                v1 = v1 * 10 + version1[i++] - '0';
            // skip .
            ++i;
            
            int v2 = 0;
            while (j < n2 && version2[j] != '.') 
                v2 = v2 * 10 + version2[j++] - '0';
            // skip .
            ++j;
            
            // cout << v1 << " " << v2 << endl;
            
            if (v1 == v2) continue;
            return v1 > v2 ? 1 : -1;
        }
        
        if (i >= n1 && j >= n2) return 0;
        
        while (i < n1) {
            int v1 = 0;
            while (i < n1 && version1[i] != '.') 
                v1 = v1 * 10 + version1[i++] - '0';
            // skip .
            ++i;
            if (v1 > 0) return 1;
        }
        
        while (j < n2) {
            int v2 = 0;
            while (j < n2 && version2[j] != '.') 
                v2 = v2 * 10 + version2[j++] - '0';
            // skip .
            ++j;
            if (v2 > 0) return -1;
        }
        
        return 0;
    }
};