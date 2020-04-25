// 519. Random Flip Matrix

// Wrong Answer
// 12 / 19 test cases passed.
class Solution {
public:
    Solution(int n_rows, int n_cols) 
    : ROWS(n_rows)
    , COLS(n_cols)
    , N(n_rows * n_cols)
    , intervals{{0, n_rows * n_cols}}
    , weights{n_rows * n_cols} {
        
    }
    
    vector<int> flip() {
        int weight = rand() % weights.back();
        int idx = lower_bound(begin(weights), end(weights), weight) - begin(weights);
        // cout << idx << endl;
        
        int s = intervals[idx].first;
        int e = intervals[idx].second;
        int n = rand() % (e - s) + s;
        // printf("[%d, %d) [%d, %d)\n", s, n, n + 1, e);
        
        if (s + 1 >= e) {
            // 1. [s, s+1)
            intervals.erase(begin(intervals) + idx);
            weights.erase(begin(weights) + idx);
            for (int i = idx; i < weights.size(); ++i) weights[i] -= 1;
        } else if (s == n) {
            // 2. [s+1, e)
            intervals[idx].first = n;
            for (int i = idx; i < weights.size(); ++i) weights[i] -= 1;
        } else if (e - 1 == n) {
            // 3.[s, e-1)
            intervals[idx].second = n;
            for (int i = idx; i < weights.size(); ++i) weights[i] -= 1;
        } else {
            // [s, n) [n+1, e)
            intervals[idx].second = n;
            intervals.insert(begin(intervals) + idx + 1, {n + 1, e});
            
            weights.insert(begin(weights) + idx + 1, weights[idx] - 1);
            weights[idx] -= e - n;
            for (int i = idx + 2; i < weights.size(); ++i) weights[i] -= 1;
        }
        
        // cout << "    "; for (auto& p : intervals) printf("[%d, %d) ", p.first, p.second); cout << endl;
        // cout << "    "; for (int w : weights) cout << w << " "; cout << endl;
        
        return {n / COLS, n % COLS};
    }
    
    void reset() {
        intervals = {pair<int, int>(0, ROWS * COLS)};
        weights = {ROWS * COLS};
    }
    
    const int ROWS;
    const int COLS;
    const int N;
    
    // [start, end)
    vector<pair<int, int>> intervals;
    vector<int> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */