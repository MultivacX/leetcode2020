// 933. Number of Recent Calls
// https://leetcode.com/problems/number-of-recent-calls/

// Runtime: 200 ms, faster than 79.62% of C++ online submissions for Number of Recent Calls.
// Memory Usage: 57.8 MB, less than 74.94% of C++ online submissions for Number of Recent Calls.
    
class RecentCounter {
    queue<int> q;
    
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */