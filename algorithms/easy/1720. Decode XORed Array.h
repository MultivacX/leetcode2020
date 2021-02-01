// 1720. Decode XORed Array
// https://leetcode.com/problems/decode-xored-array/

// Runtime: 20 ms, faster than 99.09% of C++ online submissions for Decode XORed Array.
// Memory Usage: 24.8 MB, less than 95.27% of C++ online submissions for Decode XORed Array.
    
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(encoded.size() + 1);
        ans[0] = first;
        for (int i = 0; i < encoded.size(); ++i) 
            ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};