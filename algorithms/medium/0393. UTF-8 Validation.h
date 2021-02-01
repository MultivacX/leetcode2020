// 393. UTF-8 Validation

// Runtime: 28 ms, faster than 16.28% of C++ online submissions for UTF-8 Validation.
// Memory Usage: 14.3 MB, less than 12.50% of C++ online submissions for UTF-8 Validation.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const int N = data.size();
        int i = 0;
        auto check = [&](int len){
            // cout << i << " + " << len << " <> " << N << endl; 
            if (i + len > N) return false;
            for (int j = i; j < i + len; ++j)
                if (0b10000000 > data[j] || data[j] > 0b10111111)
                    return false;
            i += len;
            return true;
        };
        // for (int d : data) cout << bitset<8>(d) << endl;
        while (i < N) {
            // cout << " " << bitset<8>(data[i]) << endl;
            
            if (0 <= data[i] && data[i] <= 0b01111111) {
                ++i;
            } else if (0b11000000 <= data[i] && data[i] <= 0b11011111) {
                ++i;
                if (!check(1)) return false;
            } else if (0b11100000 <= data[i] && data[i] <= 0b11101111) {
                ++i;
                if (!check(2)) return false;
            } else if (0b11110000 <= data[i] && data[i] <= 0b11110111) {
                ++i;
                if (!check(3)) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};