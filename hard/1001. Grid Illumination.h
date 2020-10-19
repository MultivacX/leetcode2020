// 1001. Grid Illumination
// https://leetcode.com/problems/grid-illumination/

// Runtime: 704 ms, faster than 97.62% of C++ online submissions for Grid Illumination.
// Memory Usage: 105.3 MB, less than 5.71% of C++ online submissions for Grid Illumination.

class Solution {
    int64_t N_;
    unordered_set<int64_t> lamps_;
    unordered_map<int64_t, int> leftTops;
    unordered_map<int64_t, int> leftBottoms;
    unordered_map<int64_t, int> lefts;
    unordered_map<int64_t, int> tops;
    
    int64_t getLeftTop(int64_t x, int64_t y) { 
        int64_t i = min(x, y); 
        return (x - i) * N_ + (y - i); 
    }
    
    int64_t getLeftBottom(int64_t x, int64_t y) { 
        int64_t i = min(x, N_ - 1 - y); 
        return (x - i) * N_ + (y + i); 
    }
    
    void initLamps(int N, vector<vector<int>>& lamps) {
        N_ = N;
        for (const auto& lamp : lamps) {
            int64_t x = lamp[0];
            int64_t y = lamp[1];
            lamps_.insert(x * N_ + y);
            ++leftTops[getLeftTop(x, y)];
            ++leftBottoms[getLeftBottom(x, y)];
            ++lefts[x];
            ++tops[y];
        }
    }
    
    void turnOff(int64_t xx, int64_t yy) {
        static const vector<vector<int>> offsets{
            {0, 0}, 
            {0, 1}, {0, -1}, {1, -1}, {1, 1},                            
            {1, 0}, {-1, 0}, {-1, 1}, {-1, -1},                            
        };
        
        for (const auto& o : offsets) {
            int x = xx + o[0];
            int y = yy + o[1];
            if (x < 0 || x >= N_ || y < 0 || y >= N_ || lamps_.count(x * N_ + y) == 0) 
                continue;
            
            lamps_.erase(x * N_ + y);
            if (--leftTops[getLeftTop(x, y)] == 0) leftTops.erase(getLeftTop(x, y));
            if (--leftBottoms[getLeftBottom(x, y)] == 0) leftBottoms.erase(getLeftBottom(x, y));
            if (--lefts[x] == 0) lefts.erase(x);
            if (--tops[y] == 0) tops.erase(y);
        }
    }
    
    int query(int64_t x, int64_t y) {
        if (lefts.count(x) || 
            tops.count(y) || 
            leftTops.count(getLeftTop(x, y)) || 
            leftBottoms.count(getLeftBottom(x, y))) {
            turnOff(x, y);
            return 1;
        }
        return 0;
    }
    
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        initLamps(N, lamps);
        vector<int> ans;
        for (const auto& q : queries) 
            ans.push_back(query(q[0], q[1]));
        return ans;
    }
};

// 31 / 38 test cases passed.
// Status: Time Limit Exceeded
/*class Solution {
    using I2JS = unordered_map<int, unordered_set<int>>;
    using JS = unordered_map<int, int>;
    
    void turnOff(int N, I2JS& i2js, JS& js, int i, int j) {
        static const vector<vector<int>> offsets{
            {0, 0}, 
            {0, 1}, {0, -1}, {1, -1}, {1, 1},                            
            {1, 0}, {-1, 0}, {-1, 1}, {-1, -1},                            
        };
        for (const auto& o : offsets) {
            int ii = i + o[0];
            int jj = j + o[1];
            if (ii < 0 || ii >= N || jj < 0 || jj >= N || i2js.count(ii) == 0 || i2js[ii].count(jj) == 0) 
                continue;

            i2js[ii].erase(jj);
            if (i2js[ii].empty()) i2js.erase(ii);

            if (--js[jj] == 0) js.erase(jj);
        }
    }
    
    bool findDiagonals(I2JS& i2js, int i, int j) {
        for (auto it : i2js) {
            int oi = it.first - i;
            for (int jl : it.second) {
                int oj = jl - j;
                if (oi == oj || oi == -oj)
                    return true;
            }
        }
        return false;
    }
    
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        I2JS i2js;
        JS js;
        for (const auto& v : lamps) {
            int i = v[0];
            int j = v[1];
            i2js[i].insert(j);
            ++js[j];
        }
        
        vector<int> ans;
        for (const auto& v : queries) {
            int i = v[0];
            int j = v[1];
            if (i2js.count(i) || js.count(j) || findDiagonals(i2js, i, j)) {
                turnOff(N, i2js, js, i, j);
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            
            // printf("[%d,%d]: \n", i, j);
            // for (auto it : i2js) for (int jl : it.second) printf("  [%d,%d] ", it.first, jl); cout << endl;
        }
        return ans;
    }
};*/