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