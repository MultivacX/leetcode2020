// 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/

// Runtime: 232 ms, faster than 76.51% of C++ online submissions for My Calendar II.
// Memory Usage: 34.2 MB, less than 5.24% of C++ online submissions for My Calendar II.

class MyCalendarTwo {
    vector<array<int, 2>> events;
    vector<array<int, 2>> overlaps;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& e : overlaps) {
            int s_ = max(e[0], start);
            int e_ = min(e[1], end);
            if (s_ < e_) return false;
        }
        
        for (auto& e : events) {
            int s_ = max(e[0], start);
            int e_ = min(e[1], end);
            if (s_ < e_) overlaps.push_back(array<int, 2>{s_, e_});
        }
        
        events.push_back(array<int, 2>{start, end});
        
        return true;
    }
};

// Wrong Answer
// 89 / 98 test cases passed.
class MyCalendarTwo {
    map<int, int> one;
    map<int, int> two;
    
    map<int, int>::iterator findOverlap(map<int, int>& events, int start, int end) {
        if (events.empty()) return events.end();
        
        auto it = events.lower_bound(end);
        if (it == events.begin()) return events.end();
        
        --it;
        int cur_start = it->first;
        int cur_end = it->second;
        if (cur_end <= start) return events.end();
        return it;
    }
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto it2 = findOverlap(two, start, end);
        if (it2 != two.end()) return false;
        
        auto it1 = findOverlap(one, start, end);
        while (it1 != one.end()) {
            int cur_start = it1->first;
            int cur_end = it1->second;
            
            int s = max(cur_start, start);
            int e = min(cur_end, end);
            if (s < e) {
                two.emplace(s, e);
            }

            if (it1 == one.begin()) break;
            --it1;
        }
        one.emplace(start, end);
        return true;
    }
};

