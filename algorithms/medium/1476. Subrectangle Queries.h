// 1476. Subrectangle Queries
// https://leetcode.com/problems/subrectangle-queries/

// Runtime: 80 ms, faster than 83.64% of C++ online submissions for Subrectangle Queries.
// Memory Usage: 18.5 MB, less than 100.00% of C++ online submissions for Subrectangle Queries.

class SubrectangleQueries {
    const vector<vector<int>>& rectangle_;
    vector<vector<int>> newValues_;
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle_(rectangle) {
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        newValues_.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        const int N = newValues_.size();
        for (int i = N - 1; i >= 0; --i) {
            int row1 = newValues_[i][0];
            int col1 = newValues_[i][1];
            int row2 = newValues_[i][2];
            int col2 = newValues_[i][3];
            if (row1 <= row && row <= row2 && col1 <= col && col <= col2)
                return newValues_[i][4];
        }
        return rectangle_[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */