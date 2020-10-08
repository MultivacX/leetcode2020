// 391. Perfect Rectangle
// https://leetcode.com/problems/perfect-rectangle

// Runtime: 244 ms, faster than 79.56% of C++ online submissions for Perfect Rectangle.
// Memory Usage: 36.9 MB, less than 13.35% of C++ online submissions for Perfect Rectangle.

class Solution {
    unordered_map<string, int> m;
    
    bool count(const vector<int>& rect) {
        string x0(to_string(rect[0]) + ",");
        string y0(to_string(rect[1]));
        string x1(to_string(rect[2]) + ",");
        string y1(to_string(rect[3]));
        
        if (m[x0 + y0] & 0b0001) return false;
        if (m[x0 + y1] & 0b0010) return false;
        if (m[x1 + y0] & 0b0100) return false;
        if (m[x1 + y1] & 0b1000) return false;

        m[x0 + y0] |= 0b0001;
        m[x0 + y1] |= 0b0010;
        m[x1 + y0] |= 0b0100;
        m[x1 + y1] |= 0b1000;

        return true;
    }

    bool count4Coners(int minX, int minY, int maxX, int maxY) {
        string x0(to_string(minX) + ",");
        string y0(to_string(minY));
        string x1(to_string(maxX) + ",");
        string y1(to_string(maxY));
        
        if (m[x0 + y0] != 0b0001) return false;
        if (m[x0 + y1] != 0b0010) return false;
        if (m[x1 + y0] != 0b0100) return false;
        if (m[x1 + y1] != 0b1000) return false;

        m.erase(x0 + y0);
        m.erase(x0 + y1);
        m.erase(x1 + y0);
        m.erase(x1 + y1);

        return true;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int64_t areaSum = 0;
        int minX = INT_MAX;
        int maxX = INT_MIN;
        int minY = INT_MAX;
        int maxY = INT_MIN;
        for (const auto& rect : rectangles) {
            if (!count(rect)) return false;

            int x0 = rect[0];
            int y0 = rect[1];
            int x1 = rect[2];
            int y1 = rect[3];
            
            minX = min(minX, x0);
            maxX = max(maxX, x1);
            minY = min(minY, y0);
            maxY = max(maxY, y1);

            areaSum += (int64_t)(x1 - x0) * (int64_t)(y1 - y0);
        }
        int64_t area = (int64_t)(maxX - minX) * (int64_t)(maxY - minY);
        if (area != areaSum || !count4Coners(minX, minY, maxX, maxY)) return false;

        for (auto it : m) {
            int val = it.second;
            
            if (val == 0b0001) return false;
            if (val == 0b0010) return false;
            if (val == 0b0100) return false;
            if (val == 0b1000) return false;

            if (val == 0b0111) return false;
            if (val == 0b1011) return false;
            if (val == 0b1101) return false;
            if (val == 0b1110) return false;
        }

        return true;
    }
};

// Time Limit Exceeded
// 41 / 46 test cases passed.
/*class Solution {
    bool overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l = max(A, E);
        int b = max(B, F);
        int r = min(C, G);
        int t = min(D, H);
        return l < r && b < t;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        auto cmp = [](const vector<int>& l, const vector<int>& r) -> bool { return l[2] < r[2] || (l[2] == r[2] && l[0] < r[0]); };
        sort(begin(rectangles), end(rectangles), cmp);
        
        // for (const auto& rect : rectangles) printf("%d, %d, %d, %d\n", rect[0], rect[1], rect[2], rect[3]);
        
        int i = 0;
        int area = (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        int x0 = rectangles[i][0];
        int y0 = rectangles[i][1];
        int x1 = rectangles[i][2];
        int y1 = rectangles[i][3];
        
        for (i = 1; i < rectangles.size(); ++i) {
            area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            x0 = min(x0, rectangles[i][0]);
            y0 = min(y0, rectangles[i][1]);
            x1 = max(x1, rectangles[i][2]);
            y1 = max(y1, rectangles[i][3]);
            
            vector<int> tmp{rectangles[i][0], 0, rectangles[i][0], 0};
            auto it = upper_bound(begin(rectangles), end(rectangles), tmp, cmp);
            for (; it != end(rectangles); ++it) { 
                if (it - begin(rectangles) == i) continue;
                if (rectangles[i][0] > (*it)[2]) break;
                if (overlap(rectangles[i][0], rectangles[i][1], rectangles[i][2], rectangles[i][3], 
                            (*it)[0], (*it)[1], (*it)[2], (*it)[3])) return false;
            }
        }
        return area == (x1 - x0) * (y1 - y0);
    }
};*/
