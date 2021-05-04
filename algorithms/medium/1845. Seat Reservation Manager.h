// 1845. Seat Reservation Manager
// https://leetcode.com/problems/seat-reservation-manager/

// Runtime: 364 ms, faster than 88.71% of C++ online submissions for Seat Reservation Manager.
// Memory Usage: 157.6 MB, less than 54.54% of C++ online submissions for Seat Reservation Manager.
    
class SeatManager {
    const int seats;
    
    priority_queue<int, vector<int>, greater<int>> unreserved;
    unordered_set<int> reserved;
    
public:
    SeatManager(int n) : seats(n) {
        
    }
    
    int reserve() {
        int ans = 0;
        if (unreserved.empty()) {
            ans = reserved.size() + 1;
        } else {
            ans = unreserved.top();
            unreserved.pop();
        }
        reserved.insert(ans);
        return ans;
    }
    
    void unreserve(int seatNumber) {
        reserved.erase(seatNumber);
        unreserved.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */