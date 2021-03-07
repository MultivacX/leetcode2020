// 681. Next Closest Time
// https://leetcode.com/problems/next-closest-time/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Closest Time.
// Memory Usage: 6 MB, less than 97.64% of C++ online submissions for Next Closest Time.
    
class Solution {
public:
    string nextClosestTime(string time) {
        int nums[4] = {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        int h = nums[0] * 10 + nums[1];
        int m = nums[2] * 10 + nums[3];
        int d = INT_MAX;
        string s;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int nh = nums[i] * 10 + nums[j];
                if (nh >= 24) continue;
                
                for (int x = 0; x < 4; ++x) {
                    for (int y = 0; y < 4; ++y) {
                        int nm = nums[x] * 10 + nums[y];
                        if (nm >= 60) continue;
                        
                        int distance = nh * 60 + nm - h *60 - m;
                        if (nh < h || (nh == h && nm <= m)) 
                            distance += 24 * 60;
                        if (distance < d) {
                            d = distance;
                            s.clear();
                            s += (nums[i] + '0');
                            s += (nums[j] + '0');
                            s += ':';
                            s += (nums[x] + '0');
                            s += (nums[y] + '0');
                        }
                    }
                }
            }
        }
        return s;
    }
};


class Solution {
    int getMinutes(char a, char b, char c, char d) {
        return ((a - '0') * 10 + b - '0') * 60 + (c - '0') * 10 + d - '0';
    }
    
public:
    string nextClosestTime(string time) {
        unordered_set<char> digits{time[0], time[1], time[3], time[4]};
        if (digits.size() == 1) return time;
        
        const int l = 0, r = 24 * 60;
        const int minutes = getMinutes(time[0], time[1], time[3], time[4]);
        
        string ans(time);
        int diff = INT_MAX;
        for (char a : digits) {
            if (a > '2') continue;
            for (char b : digits) {
                if (a == '2' && b > '3') continue;
                for (char c : digits) {
                    if (c > '5') continue;
                    for (char d : digits) {
                        if (time[0] == a && time[1] == b && time[3] == c && time[4] == d)
                            continue;
                        int cur = getMinutes(a, b, c, d);
                        if (cur < minutes) cur += r;
                        // printf("%c%c:%c%c  %d\n", a, b, c, d, cur);
                        if (cur - minutes < diff) {
                            ans[0] = a, ans[1] = b, ans[3] = c, ans[4] = d;
                            diff = cur - minutes;
                        }
                    }
                }
            }
        }
        return ans;
    }
};