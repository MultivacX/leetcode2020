// 352. Data Stream as Disjoint Intervals

// Runtime: 104 ms, faster than 96.79% of C++ online submissions for Data Stream as Disjoint Intervals.
// Memory Usage: 26 MB, less than 100.00% of C++ online submissions for Data Stream as Disjoint Intervals.

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> new_interval{val, val};
        if (intervals.empty()) {
            intervals.emplace_back(new_interval);
            return;
        }
        
        auto it = lower_bound(intervals.begin(), intervals.end(), new_interval);
        if (it == intervals.end()) {
            auto pre = it - 1;
            if ((*pre)[1] < val - 1) {
                intervals.emplace_back(new_interval);
            } else {
                (*pre)[1] = max((*pre)[1], val);
            }
        } else if (it == intervals.begin()) {
            if (val + 1 < (*it)[0]) {
                intervals.emplace(it, new_interval);
            } else {
                (*it)[0] = val;
            }
        } else {
            auto pre = it - 1;
            if ((*pre)[1] < val - 1 && val + 1 < (*it)[0]) {
                intervals.emplace(it, new_interval);
                return;
            } else if ((*pre)[1] == val - 1) {
                (*pre)[1] = val;
            } else if (val + 1 == (*it)[0]) {
                (*it)[0] = val;
            }
            
            if ((*pre)[1] + 1 >= (*it)[0]) {
                (*pre)[1] = (*it)[1];
                intervals.erase(it);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
    
    vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */