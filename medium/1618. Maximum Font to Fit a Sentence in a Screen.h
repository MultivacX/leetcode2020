// 1618. Maximum Font to Fit a Sentence in a Screen
// https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/

// Runtime: 68 ms, faster than 51.45% of C++ online submissions for Maximum Font to Fit a Sentence in a Screen.
// Memory Usage: 14.8 MB, less than 12.45% of C++ online submissions for Maximum Font to Fit a Sentence in a Screen.
    
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int l = 0, r = fonts.size(), ans = -1;
        while (l < r) {
            int m = l + (r - l) / 2;
            
            int hh = fontInfo.getHeight(fonts[m]);
            if (hh > h) {
                r = m;
                continue;
            }
            
            int ww = 0;
            for (char c : text) {
                ww += fontInfo.getWidth(fonts[m], c);
                if (ww > w) break;
            }
            
            // hh <= h
            if (ww > w) {
                r = m;
            } else {
                // ww <= w && hh <= h
                l = m + 1;
                ans = fonts[m];
            }
        }
        return ans;
    }
};