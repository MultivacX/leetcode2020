// 963. Minimum Area Rectangle II

// Runtime: 156 ms, faster than 28.52% of C++ online submissions for Minimum Area Rectangle II.
// Memory Usage: 34.9 MB, less than 40.00% of C++ online submissions for Minimum Area Rectangle II.

// Time Complexity: O(N*N*K). K, Number of diagonals of same length.
// Space Complexity: O(N*N). Number of diagonals.

class Solution {
public:
    struct Diagonal {
        Diagonal(vector<int>& a, vector<int>& b) 
        : A(a)
        , B(b) 
        , slope(get_slope(a, b))
        , length_square(get_length_square(a, b)) {
            
        }
        
        vector<int> A;
        vector<int> B;
        vector<int> slope;
        uint64_t length_square;
        
        void print(bool ab = true) {
            if (ab) printf("A:(%d, %d), B:(%d, %d), slope:(%d, %d), ls:%lld\n", A[0], A[1], B[0], B[1], slope[0], slope[1], length_square);
            else printf("C:(%d, %d), D:(%d, %d), slope:(%d, %d), ls:%lld\n", A[0], A[1], B[0], B[1], slope[0], slope[1], length_square);
        }
        
        static vector<int> get_slope(vector<int>& A, vector<int>& B) {
            int x = A[0] - B[0];
            int y = A[1] - B[1];

            if (y == 0 && x == 0) return {0, 0};
            if (y == 0 && x > 0) return {0, 1};
            if (y == 0 && x < 0) return {0, 1};
            if (y > 0 && x == 0) return {1, 0};
            if (y < 0 && x == 0) return {1, 0};

            int i = ((y > 0 && x > 0) || (y < 0 && x < 0)) ? 1 : -1;
            y = abs(y);
            x = abs(x);
            auto g = gcd(y, x);
            return {i * x / g, y / g};
        }
        
        static uint64_t get_length_square(vector<int>& A, vector<int>& B) {
            return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]);
        }
        
        static double rectangle_area(Diagonal& AB, Diagonal& CD) {
            // if (AB.length_square != CD.length_square) return 0;
            if (AB.slope[0] == CD.slope[0] && AB.slope[1] == CD.slope[1]) return -1;
            
            auto& A = AB.A;   
            auto& B = AB.B;
            
            auto& C = CD.A;   
            auto& D = CD.B;
            
            uint64_t ls_AC = get_length_square(A, C);
            uint64_t ls_BD = get_length_square(B, D);
            if (ls_AC != ls_BD) return -1;
            
            uint64_t ls_AD = get_length_square(A, D);
            uint64_t ls_BC = get_length_square(B, C);
            if (ls_AD != ls_BC) return -1;
            
            return sqrt(ls_AC * ls_AD);
        }
    };
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        // {length_square, {Diagonal}}
        unordered_map<uint64_t, vector<Diagonal>> m;
        double ans = -1;
        for (int i = 0; i + 1 < points.size(); ++i) {
            auto& A = points[i];
            for (int j = i + 1; j < points.size(); ++j) {
                auto& B = points[j];
                Diagonal AB(A, B);
                if (m.count(AB.length_square)) {
                    // AB.print();
                    for (auto& CD : m[AB.length_square]) {
                        double area = Diagonal::rectangle_area(AB, CD);
                        // cout << "    " << area << " "; CD.print(false);
                        if (area < 0) continue;
                        ans = ans < 0 ? area : min(ans, area);
                    }
                }
                m[AB.length_square].push_back(AB);
            }
        }
        return ans < 0 ? 0 : ans;
    }
};