// 593. Valid Square

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Square.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Valid Square.

class Solution {
public:
    using t3 = tuple<int, vector<int>, vector<int>>;
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<t3> sides;
        sides.emplace_back(side_square(p1, p2), p1, p2);
        sides.emplace_back(side_square(p1, p3), p1, p3);
        sides.emplace_back(side_square(p1, p4), p1, p4);
        sort(begin(sides), end(sides), [](t3& l, t3&r){ return get<0>(l) < get<0>(r); });
        
        int side = get<0>(sides[0]);
        int diagonal = get<0>(sides[2]);
        // printf("side:%d, diagonal:%d\n", side, diagonal);
        if (side == 0 || side != get<0>(sides[1]) || side * 2 != diagonal) return false;
        
        // diagonal
        auto& p_0 = get<1>(sides[0]);
        auto& p_1 = get<2>(sides[2]);
        // printf("[%d,%d] <> [%d,%d]\n", p_0[0], p_0[1], p_1[0], p_1[1]);
        
        // diagonal
        auto& p_2 = get<2>(sides[0]);
        auto& p_3 = get<2>(sides[1]);
        // printf("[%d,%d] <> [%d,%d]\n", p_2[0], p_2[1], p_3[0], p_3[1]);
        
        if (side_square(p_1, p_2) != side || side_square(p_1, p_3) != side || side_square(p_2, p_3) != diagonal) return false;
        return true;
    }
    
    int side_square(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};