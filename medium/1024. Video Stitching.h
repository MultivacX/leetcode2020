// 1024. Video Stitching
// https://leetcode.com/problems/video-stitching/submissions/

// Runtime: 4 ms, faster than 94.27% of C++ online submissions for Video Stitching.
// Memory Usage: 7.8 MB, less than 58.28% of C++ online submissions for Video Stitching.

// Time Complexity: O(N * logN), where N is the length of clips.
// Space Complexity: O(N).

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(begin(clips), end(clips));
        if (clips[0][0] != 0) return -1;
        
        vector<int> s;
        s.push_back(0);
        for (int i = 1; i < clips.size(); ++i) {
            auto& pre = clips[s.back()];
            if (pre[1] >= T) return s.size();
            
            auto& cur = clips[i];
            
            // cout << pre[0] << " " << pre[1] << " -- ";
            // cout << cur[0] << " " << cur[1] << endl;
            
            // [2, 3) -> [5, 6)
            if (pre[1] < cur[0]) return -1;
            
            // [2, 6) -> [3, 4)
            if (pre[1] >= cur[1]) continue; 
            
            // [2, 3) -> [2, 6)
            if (pre[0] == cur[0]) {
                s.back() = i;
                continue;
            }
            
            int size = s.size();
            while (size > 1 && clips[s[size - 2]][1] >= cur[0]) {
                s.pop_back();
                --size;
            }
            s.push_back(i);
        }
        return clips[s.back()][1] >= T ? (int)s.size() : -1;
    }
};