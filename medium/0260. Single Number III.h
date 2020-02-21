// 260. Single Number III

// Runtime: 12 ms, faster than 94.52% of C++ online submissions for Single Number III.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Single Number III.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums) x ^= num;
        // cout << x << endl;
        
        for (int i = 0; i < 32; ++i) {
            if (x & (1 << i)) {
                x = 1 << i;
                break;
            }
        }
        // cout << x << endl;
        
        int n1 = 0;
        int n2 = 0;
        for (int num : nums) {
            if (x & num) {
                // cout << x << ":" << num << endl;
                n1 ^= num;
            } else {
                // cout << (~x) << ":" << num << endl;
                n2 ^= num;
            }
        }
        
        return {n1, n2};
    }
};