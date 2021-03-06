// 251. Flatten 2D Vector
// https://leetcode.com/problems/flatten-2d-vector/

// Runtime: 68 ms, faster than 14.75% of C++ online submissions for Flatten 2D Vector.
// Memory Usage: 23.7 MB, less than 86.60% of C++ online submissions for Flatten 2D Vector.
    
class Vector2D {
    const vector<vector<int>>& _v;
    const int ROWS;
    int i;
    int j;
    
public:
    Vector2D(vector<vector<int>>& v) : _v(v), ROWS(v.size()), i(0), j(0) {
        
    }
    
    int next() {
        while (_v[i].empty()) {
            ++i;
            j = 0;
        }
        int val = _v[i][j];
        if (++j >= _v[i].size()) ++i, j = 0;
        return val;
    }
    
    bool hasNext() {
        while (i < ROWS && _v[i].empty()) ++i;
        if (i >= ROWS) return false;
        if (i + 1 == ROWS && j >= _v[i].size()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class Vector2D {
    vector<vector<int>>& v_;
    vector<vector<int>>::iterator i;
    vector<int>::iterator j;
    
public:
    Vector2D(vector<vector<int>>& v) 
    : v_(v) {
        if (v.empty()) {
            i = v.end();
        } else if (v[0].empty()) {
            i = v.begin();
            j = i->end();
        } else {
            i = v.begin();
            j = i->begin();
        }
    }
    
    int next() {
        hasNext();
        int val = *j;
        // cout << val << " ";
        ++j;
        return val;
    }
    
    bool hasNext() {
        if (i == v_.end()) return false;
        while (j == i->end()) {
            if (++i == v_.end()) return false;
            j = i->empty() ? i->end() : i->begin();
        }
        return true;
    }
};