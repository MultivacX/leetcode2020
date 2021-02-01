// 281. Zigzag Iterator
// https://leetcode.com/problems/zigzag-iterator/

// Runtime: 12 ms, faster than 88.72% of C++ online submissions for Zigzag Iterator.
// Memory Usage: 8.1 MB, less than 34.21% of C++ online submissions for Zigzag Iterator.
    
class ZigzagIterator {
    vector<vector<int>> v;
    
    int i;
    int j;
        
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    : v({v1, v2}), i(v1.empty() ? 1 : 0), j(0) {
        
    }

    int next() {
        int val = v[i][j];
        if (i == 0) {
            if (j < v[1].size()) i = 1;
            else ++j;
        } else {
            if (j + 1 < v[0].size()) i = 0, ++j;
            else ++j;
        }
        return val;
    }

    bool hasNext() {
        return j < v[i].size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */