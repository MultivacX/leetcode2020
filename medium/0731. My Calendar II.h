// 731. My Calendar II

class MyCalendarTwo {
public:

    /* WRONG
    // start, end, count
    map<int, pair<int, int>> events;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto it = lower_bound(events.begin(), events.end(), start);
        
        if (it == events.end()) {
            // empty
            if (it == events.begin()) {
                events.insert({start, {end, 1}});
                return true;
            } 
            
            --it;
            int preS = it->first;
            int preE = it->second.first;
            int cnt = it->second.second;
            
            if (preE <= start) {
                events.insert({start, {end, 1}});
                return true;
            } else if (cnt > 1) {
                return false;
            } 
            
            events.erase(it);
            events.insert({preS, {start, 1}});
            events.insert({start, {min(preE, end), 2}});
            if (preE != end) {
                events.insert({min(preE, end), {max(preE, end), 1}});
            }
            return true;
        }
        
        if (it == events.begin()) {
            int nextS = it->first;
            int nextE = it->second.first;
            int cnt = it->second.second;
            
            if (end <= nextS) {
                events.insert({start, {end, 1}});
                return true;
            } else if (cnt > 1) {
                return false;
            } 
            
            events.erase(it);
            if (start == nextS) {
                events.insert({start, {min(nextE, end), 2}});
                if (end != nextE) {
                    events.insert({min(nextE, end), {max(nextE, end), 1}});
                }
                return true;
            }
            
            events.insert({start, {nextS, 1}});
            events.insert({nextS, {min(nextE, end), 2}});
            if (end != nextE) {
                events.insert({min(nextE, end), {max(nextE, end), 1}});
            }
            return true;
        }
        
        // pre_s < start <= next_s
        // end > start
    }*/
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */