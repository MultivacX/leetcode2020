// 391. Perfect Rectangle

// WRONG
class Solution {    
    unordered_map<string, int> m;
    
    bool count(vector<int>& rect) {
        string x0(to_string(rect[0]) + ",");
        string y0(to_string(rect[1]));
        string x1(to_string(rect[2]) + ",");
        string y1(to_string(rect[3]));
        
        if (++m[x0+y0] > 4) return false;
        if (++m[x0+y1] > 4) return false;
        if (++m[x1+y0] > 4) return false;
        if (++m[x1+y1] > 4) return false;
        return true;
    }
    
    bool count_corners(int x0_, int y0_, int x1_, int y1_) {
        string x0(to_string(x0_) + ",");
        string y0(to_string(y0_));
        string x1(to_string(x1_) + ",");
        string y1(to_string(y1_));
        
        if (m[x0+y0] != 1) return false;
        if (m[x0+y1] != 1) return false;
        if (m[x1+y0] != 1) return false;
        if (m[x1+y1] != 1) return false;
        m.erase(x0+y0);
        m.erase(x0+y1);
        m.erase(x1+y0);
        m.erase(x1+y1);
        return true;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
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
            
            if (!count(rectangles[i])) return false;
        }
        
        if (area != (x1 - x0) * (y1 - y0)) return false;
        if (!count_corners(x0, y0, x1, y1)) return false;
        for (auto& it : m) if (it.second != 4) return false;
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