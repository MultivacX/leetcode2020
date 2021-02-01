// 1151. Minimum Swaps to Group All 1's Together
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

// Runtime: 180 ms, faster than 45.18% of C++ online submissions for Minimum Swaps to Group All 1's Together.
// Memory Usage: 69 MB, less than 52.41% of C++ online submissions for Minimum Swaps to Group All 1's Together.
    
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int all = accumulate(begin(data), end(data), 0);
        int cur = accumulate(begin(data), begin(data) + all, 0);
        int cnt = all - cur;
        // int s = 0; for (int i : data) s += i; cout << all << " " << s << endl;
        // int c = 0; for (int i = 0; i < s; ++i) c += data[i]; cout << cur << " " << c << endl;
        for (int i = 1; i + all <= data.size() && cnt > 0; ++i) {
            // cout << "[" << i << "," << i + all - 1 << "] " << cur << " - ";
            cur = cur - data[i - 1] + data[i + all - 1];
            cnt = min(cnt, all - cur);
            // cout << data[i - 1] << " + " << data[i + all - 1] << ":  ";
            // int c = 0; for (int j = i; j < i + all; ++j) c += data[j]; cout << cur << " " << c << endl;
        }
        return cnt;
    }
};