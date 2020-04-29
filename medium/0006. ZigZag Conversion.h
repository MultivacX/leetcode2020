// 6. ZigZag Conversion

// Runtime: 40 ms, faster than 24.53% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 12.2 MB, less than 51.85% of C++ online submissions for ZigZag Conversion.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
        if (numRows == 2) {
            string t;
            for (int i = 0; i < s.length(); i += 2) t += s[i];
            for (int i = 1; i < s.length(); i += 2) t += s[i];
            return t;
        }
        
        const int numCols = 1 + s.length() / (numRows - 1);
        vector<vector<char>> v(numRows, vector<char>(numCols, '\0'));
        int k = 0;
        for (int j = 0; j < numCols; ++j)
            if (j & 1) for (int i = numRows - 2; i >= 1 && k < s.length(); --i) v[i][j] = s[k++];
            else for (int i = 0; i < numRows && k < s.length(); ++i) v[i][j] = s[k++];
        // cout << numRows << "x" << numCols << ", " << s.length() << endl;
        // for (int i = 0; i < numRows; ++i) {
        //     for (int j = 0; j < numCols; ++j) {
        //         cout << (v[i][j] != '\0' ? v[i][j] : ' ') << ' ';
        //     }
        //     cout << endl;
        // }
        string t;
        for (int i = 0; i < numRows; ++i) for (int j = 0; j < numCols; ++j) if (v[i][j] != '\0') t += v[i][j];
        return t;
    }
};