// 528. Random Pick with Weight

// Runtime: 144 ms, faster than 66.88% of C++ online submissions for Random Pick with Weight.
// Memory Usage: 31.8 MB, less than 100.00% of C++ online submissions for Random Pick with Weight.

class Solution {
public:
    Solution(vector<int>& w)
    : sums(w.size(), 0) {
        srand((unsigned)time(NULL)); 
        
        sums[0] = w[0];
        for (int i = 1; i < w.size(); ++i)
            sums[i] = sums[i - 1] + w[i];
    }
    
    int pickIndex() {
        int64_t sum = rand() % sums.back() + 1;
        auto it = lower_bound(sums.begin(), sums.end(), sum);
        int i = distance(sums.begin(), it);
        return i;
    }
    
    vector<int64_t> sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */