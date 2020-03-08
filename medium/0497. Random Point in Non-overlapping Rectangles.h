// 497. Random Point in Non-overlapping Rectangles

// Runtime: 96 ms, faster than 49.44% of C++ online submissions for Random Point in Non-overlapping Rectangles.
// Memory Usage: 25.5 MB, less than 100.00% of C++ online submissions for Random Point in Non-overlapping Rectangles.

class Solution {
public:
    Solution(vector<vector<int>>& rects)
    : rects(rects)
    , weights(rects.size(), 0) {
        srand((unsigned)time(NULL)); 
        int i = 0;
        weights[i] = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1); // + 1 : include edges
        for (i = 1; i < rects.size(); ++i) 
            weights[i] = weights[i - 1] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1); // + 1 : include edges
        
        // for (i = 0; i < rects.size(); ++i) cout << (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1) << ", ";
        // cout << endl;
        // for (int w : weights) cout << w << ", ";
        // cout << endl;
    }
    
    vector<int> pick() {
        int weight = rand() % weights.back() + 1; // (0, weights.back()]
        int i = distance(weights.begin(), lower_bound(weights.begin(), weights.end(), weight));
        int x = (rand() % (rects[i][2] - rects[i][0] + 1)) + rects[i][0];
        int y = (rand() % (rects[i][3] - rects[i][1] + 1)) + rects[i][1];
        
        // ++cnt[i];
        // if (--k == 0) for (auto it : cnt) cout << it.first << "=" << it.second << ", ";
        
        return {x, y};
    }
    
    vector<vector<int>> rects;
    vector<int> weights; // weights[i] <= 2002 * 2002 * 100
    // int k = 10000;
    // unordered_map<int, int> cnt;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

// WRONG
// 32 / 35 test cases passed.
/*
12, 1, 1, 16, 
12, 13, 14, 30, 
2=351, 1=310, 3=4979, 0=4360, 
*/
/*class Solution {
public:
    Solution(vector<vector<int>>& rects)
    : rects(rects)
    , weights(rects.size(), 0) {
        srand((unsigned)time(NULL)); 
        int i = 0;
        weights[i] = (rects[i][2] - rects[i][0]) * (rects[i][3] - rects[i][1]);
        for (i = 1; i < rects.size(); ++i) 
            weights[i] = weights[i - 1] + (rects[i][2] - rects[i][0]) * (rects[i][3] - rects[i][1]);
        
        for (i = 0; i < rects.size(); ++i) cout << (rects[i][2] - rects[i][0]) * (rects[i][3] - rects[i][1]) << ", ";
        cout << endl;
        for (int w : weights) cout << w << ", ";
        cout << endl;
    }
    
    vector<int> pick() {
        int weight = rand() % weights.back();
        int i = distance(weights.begin(), lower_bound(weights.begin(), weights.end(), weight));
        int x = (rand() % (rects[i][2] - rects[i][0] + 1)) + rects[i][0];
        int y = (rand() % (rects[i][3] - rects[i][1] + 1)) + rects[i][1];
        
        ++cnt[i];
        if (--k == 0) for (auto it : cnt) cout << it.first << "=" << it.second << ", ";
        
        return {x, y};
    }
    
    vector<vector<int>> rects;
    vector<int> weights; // weights[i] <= 2000 * 2000 * 100
    int k = 10000;
    unordered_map<int, int> cnt;
};*/