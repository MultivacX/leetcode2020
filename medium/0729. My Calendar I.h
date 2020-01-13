// 729. My Calendar I

// Runtime: 116 ms, faster than 48.07% of C++ online submissions for My Calendar I.
// Memory Usage: 34.8 MB, less than 100.00% of C++ online submissions for My Calendar I.

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> j{start, end};
        if (events.empty()) {
            events.push_back(j);
            return true;
        }
        
        auto it = upper_bound(events.begin(), events.end(), j, [](const pair<int, int>& a, const pair<int, int>& b){ return a.first < b.first; });
        
        if (it == events.end()) {
            --it;
            if (it->second <= start) {
                events.push_back(j);
                return true;
            }
            return false;
        } else if (it == events.begin()) {
            if (end <= it->first) {
                events.insert(it, j);
                return true;
            }
            return false;
        } else if (end > it->first) {
            return false;
        } else {
            auto pre = it - 1;
            if (start < pre->second) {
                return false;
            }
            events.insert(it, j);
            return true;
        }
    }
    
    vector<pair<int, int>> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */