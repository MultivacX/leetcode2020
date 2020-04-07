// 1386. Cinema Seat Allocation

// Runtime: 232 ms, faster than 85.46% of C++ online submissions for Cinema Seat Allocation.
// Memory Usage: 38.8 MB, less than 100.00% of C++ online submissions for Cinema Seat Allocation.

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> m;
        for (const auto& s : reservedSeats) {
            if (s[1] == 1 || s[1] == 10) continue;
            
            // 23 L
            if (s[1] <= 3) m[s[0]] |= 1;
            // 45 LM
            else if (s[1] <= 5) m[s[0]] |= 0b10;
            // 67 MR
            else if (s[1] <= 7) m[s[0]] |= 0b100;
            // 89 R
            else m[s[0]] |= 0b1000;
        }
        
        int ans = n * 2;
        for (const auto& s : m) {
            if ((s.second & 0b0110) == 0b0110) ans -= 2;
            else if ((s.second & 0b1010) == 0b1010) ans -= 2;
            else if ((s.second & 0b0101) == 0b0101) ans -= 2;
            else ans -= 1;
        }
        
        return ans;
    }
};

// Time Limit Exceeded
// 48 / 53 test cases passed.
/*class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // {row, 0000000000}
        unordered_map<int, int> m;
        for (const auto& s : reservedSeats) m[s[0]] |= 1 << s[1];
        
        //   1234567890
        // 0b01111111100 = 2
        // 0b01111000000 = 1
        // 0b00000111100 = 1
        // 0b00011110000 = 1
        
        static const vector<int> masks{0b01111111100, 0b01111000000, 0b00000111100, 0b00011110000};
        static const vector<int> count{2, 1, 1, 1};
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (m.count(i) == 0) { 
                ans += 2;
            } else {
                for (int j = 0; j < 4; ++j) {
                    if (((~m[i]) & masks[j]) == masks[j]) {
                        ans += count[j];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};*/