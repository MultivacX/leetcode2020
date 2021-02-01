// 335. Self Crossing

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Crossing.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Self Crossing.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
    struct Point {
        int x = 0;
        int y = 0;
    };
    
    struct Line {
        bool inited = false;
        
        // a.x <= b.x
        // a.y <= b.y
        Point a;
        Point b;
        
        void update(const Point& a_, const Point& b_) {
            inited = true;
            a = a_;
            b = b_;
        }
        
        static bool crossing(const Line& A, const Line& B) {
            if (!A.inited || !B.inited) return false;
            if (A.a.x == A.b.x) return _crossing(A, B);
            return _crossing(B, A);
        }
        
        // A is a vertical line
        static bool _crossing(const Line& A, const Line& B) {
            return A.a.y <= B.a.y && B.a.y <= A.b.y && B.a.x <= A.a.x && A.a.x <= B.b.x;
        }
    };
    
    void print(const Line& l, string desc) {
        printf("%s:{(%d, %d)--(%d, %d)}\n", desc.c_str(), l.a.x, l.a.y, l.b.x, l.b.y);
    }
    
public:
    bool isSelfCrossing(vector<int>& x) {
        Line east;
        Line north;
        Line west;
        Line south;
        
        Point cur;
        Point dest;
        Line line;
        Line pre_line;
        
        const auto& moves = x;
        const int N = moves.size();
        
        int i = 0;
        while (i < N) {
            // go north
            dest = cur; dest.y += moves[i];
            // (0, cur.y) -> (0, 0) -> (0, dest.y)
            if (pre_line.inited && cur.y <= 0 && dest.x == 0 && dest.y >= 0) return true; 
            line.update(cur, dest);
            // print(line, " "); print(north, "N"); print(south, "S");
            if (Line::crossing(line, north) || Line::crossing(line, south)) return true;
            if (pre_line.inited) south.update(pre_line.a, pre_line.b);
            pre_line.update(line.a, line.b);
            cur = dest;
            ++i; if (i >= N) break;
            
            // go west
            dest = cur; dest.x -= moves[i];
            line.update(dest, cur);
            // print(line, " "); print(west, "W"); print(east, "E");
            if (Line::crossing(line, west) || Line::crossing(line, east)) return true;
            east.update(pre_line.a, pre_line.b);
            pre_line.update(line.a, line.b);
            cur = dest;
            ++i; if (i >= N) break;
            
            // go south
            dest = cur; dest.y -= moves[i];
            line.update(dest, cur);
            // print(line, " "); print(north, "N"); print(south, "S");
            if (Line::crossing(line, north) || Line::crossing(line, south)) return true;
            north.update(pre_line.a, pre_line.b);
            pre_line.update(line.a, line.b);
            cur = dest;
            ++i; if (i >= N) break;
            
            // go east
            dest = cur; dest.x += moves[i];
            line.update(cur, dest);
            // print(line, " "); print(west, "W"); print(east, "E");
            if (Line::crossing(line, west) || Line::crossing(line, east)) return true;
            west.update(pre_line.a, pre_line.b);
            pre_line.update(line.a, line.b);
            cur = dest;
            ++i; if (i >= N) break;
        }
        return false;
    }
};