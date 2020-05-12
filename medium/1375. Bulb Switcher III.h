// 1375. Bulb Switcher III

// Runtime: 152 ms, faster than 18.92% of C++ online submissions for Bulb Switcher III.
// Memory Usage: 38.6 MB, less than 100.00% of C++ online submissions for Bulb Switcher III.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        const int N = light.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            // bulbs turned on
            int count = i + 1;
            
            // turn on bulb[cur_bulb_idx]
            int cur_bulb_idx = abs(light[i]) - 1;
            light[cur_bulb_idx] = -abs(light[cur_bulb_idx]);
            
            // left bulb is blue
            if (cur_bulb_idx == 0 || light[cur_bulb_idx - 1] == 0) {
                // when right bulbs turned on
                int j = cur_bulb_idx; while (j < N && light[j] < 0) light[j++] = 0;
                if (j == count) {
                    ++ans;   
                    // cout << "moment:" << i << endl;
                }
            }
        }
        return ans;
    }
};