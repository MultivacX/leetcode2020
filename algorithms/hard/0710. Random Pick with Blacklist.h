// 710. Random Pick with Blacklist

// Runtime: 200 ms, faster than 95.53% of C++ online submissions for Random Pick with Blacklist.
// Memory Usage: 49.4 MB, less than 100.00% of C++ online submissions for Random Pick with Blacklist.

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        srand((unsigned)time(NULL)); 
        
        sort(begin(blacklist), end(blacklist));
        
        int start = 0;
        for (int end : blacklist) {
            if (start < end) intervals.emplace_back(start, end);
            start = end + 1;
        }
        if (start < N) intervals.emplace_back(start, N);
        
        counts.emplace_back(intervals[0].second - intervals[0].first);
        for (int i = 1; i < intervals.size(); ++i)
            counts.emplace_back(intervals[i].second - intervals[i].first + counts.back());
        
        // for (auto& p : intervals) cout << "[" << p.first << ", " << p.second << "), ";
        // cout << endl;
        // for (auto& p : counts) cout << p << ", ";
        // cout << endl;
    }
    
    int pick() {
        int count = rand() % counts.back() + 1;
        int idx = lower_bound(begin(counts), end(counts), count) - begin(counts);
        int offset = count - (idx > 0 ? counts[idx - 1] : 0) - 1;
        // cout << "count:" << count << ", idx:" << idx << ", offset:" << offset << endl;
        return intervals[idx].first + offset;
    }
    
    vector<pair<int, int>> intervals;
    vector<int> counts;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */