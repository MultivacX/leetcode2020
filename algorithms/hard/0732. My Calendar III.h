// 732. My Calendar III
// https://leetcode.com/problems/my-calendar-iii/

// Runtime: 252 ms, faster than 67.10% of C++ online submissions for My Calendar III.
// Memory Usage: 26.6 MB, less than 6.45% of C++ online submissions for My Calendar III.

class MyCalendarThree {
    // {position, k}}
    map<int, int> events;

public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++events[start];
        --events[end];
        
        int K = 0;
        int k = 0;
        for (auto it : events) {
            k += it.second;
            K = max(K, k);
        }
        return K;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */