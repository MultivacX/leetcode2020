// 1390. Four Divisors

// Runtime: 56 ms, faster than 67.48% of C++ online submissions for Four Divisors.
// Memory Usage: 15.5 MB, less than 100.00% of C++ online submissions for Four Divisors.

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m{{1, 0}};
        for (const int num : nums) {
            if (m.count(num)) {
                ans += m[num];
                continue;
            }
            
            int sum = 1 + num;
            int cnt = 2;
            for (int i = 2; i * i <= num; ++i) {
                int j = num / i;
                if (i * j != num) continue;
                
                if (m.count(i) && m[i] > 0) {
                    cnt = 5;
                    break;
                }
                
                if (i == j) {
                    sum += i;
                    cnt += 1;
                } else {
                    sum += i + j;
                    cnt += 2;
                }
                
                if (cnt > 4) break;
            }
            
            if (cnt == 4) {
                ans += sum;
                m[num] = sum;
            } else {
                m[num] = 0;
            }
        }
        return ans;
    }
};