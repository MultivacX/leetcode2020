// 1299. Replace Elements with Greatest Element on Right Side
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// Runtime: 16 ms, faster than 99.65% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
// Memory Usage: 14.3 MB, less than 99.96% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
    
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        const int N = arr.size();
        for (int i = N - 1, r = -1; i >= 0; --i) {
            int v = arr[i];
            arr[i] = r;
            r = max(r, v);
        }
        return arr;
    }
};