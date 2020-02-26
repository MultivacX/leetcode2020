// 397. Integer Replacement

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Replacement.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Integer Replacement.

class Solution {
public:
    int integerReplacement(int n) {
        static const unordered_map<int, int> M{
            {2, 1}, {3, 2}, {4, 2}, {8, 3}, {16, 4}, {32, 5}, {64, 6}, 
            {128, 7}, {256, 8}, {512, 9}, {1024, 10}, {2048, 11}, 
            {4096, 12}, {8192, 13}, {16384, 14}, {32768, 15}, {65536, 16}, 
            {131072, 17}, {262144, 18}, {524288, 19}, {1048576, 20}, 
            {2097152, 21}, {4194304, 22}, {8388608, 23}, {16777216, 24}, 
            {33554432, 25}, {67108864, 26}, {134217728, 27}, {268435456, 28},
            {536870912, 29}, {1073741824, 30}, {0x7FFFFFFF, 32}};
        
        int ops = 0;
        while (n != 1) {
            // cout << n << " " << bitset<32>(n).to_string() << endl;
            auto it = M.find(n);
            if (it != M.end()) {
                ops += it->second;
                break;
            } else if ((n & 1) == 0) {
                n >>= 1;
                ++ops;
            } else if ((n & 2) == 2) {
                n += 1;
                ++ops;
            } else {
                n -= 1;
                ++ops;
            }
        }
        return ops;
    }
};