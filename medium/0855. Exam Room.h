// 855. Exam Room
// https://leetcode.com/problems/exam-room/

// Runtime: 104 ms, faster than 14.53% of C++ online submissions for Exam Room.
// Memory Usage: 15.8 MB, less than 9.44% of C++ online submissions for Exam Room.

class ExamRoom {
    int n;
    list<int> seats;
    unordered_map<int, list<int>::iterator> m;
    
public:
    ExamRoom(int N) : n(N) {
        
    }
    
    int seat() {
        if (seats.empty()) {
            seats.push_front(0);
            m.emplace(0, seats.begin());
            return 0;
        }
        
        // [0, seats.front())
        int num = -1;
        int offset = seats.front();
        // cout << -1 << ", " << seats.front() << endl;
        
        // (*it, *(it+1))
        for (auto it = seats.begin(); it != seats.end() && *it != seats.back(); ++it) {
            int l = *it;
            int r = *(++it);
            --it;
            // cout << l << ", " << r << endl;
            int t = (r - l) / 2;
            if (t > offset) {
                num = *it;
                offset = t;
            }
        }
        
        // (seats.back(), n)
        int r = n - 1 - seats.back();
        if (r > offset) {
            num = n;
            offset = r;
        }
        // cout << seats.back() << ", " << n << endl << endl;
        
        if (num == -1) {
            seats.push_front(0);
            m.emplace(0, seats.begin());
            return 0;
        } else if (num == n) {
            seats.push_back(n - 1);
            auto it = seats.end();
            --it;
            m.emplace(n - 1, it);
            return n - 1;
        } else {
            auto it = m[num];
            ++it;
            it = seats.insert(it, num + offset);
            m.emplace(num + offset, it);
            return num + offset;
        }
    }
    
    void leave(int p) {
        seats.erase(m[p]);
        m.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */