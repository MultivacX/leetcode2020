// 1326. Minimum Number of Taps to Open to Water a Garden
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

// Runtime: 24 ms, faster than 54.46% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
// Memory Usage: 15.9 MB, less than 24.79% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<array<int, 2>> ranges_;
        for (int i = 0; i < ranges.size(); ++i) {
            if (ranges[i] == 0) continue;
            int s = max(0, i - ranges[i]);
            int e = min(n, i + ranges[i]);
            ranges_.push_back({s, e});
        }
        sort(begin(ranges_), end(ranges_), [](const array<int, 2>& a, const array<int, 2>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        int start = -1;
        vector<int> stk;
        for (int i = 0; i < ranges_.size(); ++i) {
            int s = ranges_[i][0], e = ranges_[i][1];
            if (start == -1) {
                if (s != 0) break;
                start = 0;
                stk.push_back(i);
            } else {
                int j = stk.size() - 1;
                int pre_e = ranges_[stk[j]][1];
                // pre  #--------#
                // cur  s--e                  skip
                // cur    s--e                skip
                if (pre_e >= e) continue;

                // pre  #--------#
                // cur              s----e    break
                if (pre_e < s) break;

                // pre  #--------#
                // cur           s----e       push
                if (pre_e == s) {
                    stk.push_back(i);
                    continue;
                }

                // j-1  #-------#
                //   j      s-----e           pop
                // cur        s-----e         push
                if (j > 0 && ranges_[stk[j - 1]][1] >= s) {
                    stk.pop_back();
                    stk.push_back(i);
                } else {
                    stk.push_back(i);
                }
            }
        }
        if (start == 0 && ranges_[stk.back()][1] == n) return stk.size();
        return -1;
    }
};