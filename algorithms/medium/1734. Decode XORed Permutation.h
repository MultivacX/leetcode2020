// 1734. Decode XORed Permutation
// https://leetcode.com/problems/decode-xored-permutation/

// Runtime: 196 ms, faster than 26.15% of C++ online submissions for Decode XORed Permutation.
// Memory Usage: 102.1 MB, less than 51.12% of C++ online submissions for Decode XORed Permutation.
    
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        const int n = encoded.size() + 1;
        
        // p[0] ^ ... ^ p[n-1]
        int total = 0;
        for (int i = 1; i <= n; ++i)
            total ^= i;
        
        // (p[1]^p[2]) ^ (p[3]^p[4]) ^ ... ^ (p[n-2]^p[n-1])
        // p[1] ^ ... ^ p[n-1]
        int suffix = 0;
        for (int i = 1; i < n - 1; i += 2) 
            suffix ^= encoded[i];
        
        vector<int> perm{total ^ suffix};
        for (int i = 0; i < n - 1; ++i) 
            perm.push_back(perm.back() ^ encoded[i]);
        return perm;
    }
};