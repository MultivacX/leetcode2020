// 面试题56 - I. 数组中数字出现的次数

// 执行用时 : 56 ms, 在所有 C++ 提交中击败了23.66%的用户
// 内存消耗 : 16.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (int num : nums)
            x ^= num;
        int y = 0;
        for (int i = 0; i < 31; ++i) {
            if (x & (1 << i)) {
                y = 1 << i;
                break;
            }
        }

        int a = 0;
        int b = 0;
        for (int num : nums) {
            if (num & y) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};