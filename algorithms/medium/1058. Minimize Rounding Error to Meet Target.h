// 1058. Minimize Rounding Error to Meet Target
// https://leetcode.com/problems/minimize-rounding-error-to-meet-target/

// Runtime: 4 ms, faster than 90.35% of C++ online submissions for Minimize Rounding Error to Meet Target.
// Memory Usage: 8 MB, less than 81.58% of C++ online submissions for Minimize Rounding Error to Meet Target.
    
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        priority_queue<int> q;
        for (const auto& p : prices) {
            int i = p.find('.');
            // floor all
            target -= stoi(p.substr(0, i));
            if (target < 0) return "-1";
            
            int d = stoi(p.substr(i + 1));
            if (d > 0) q.push(d);
        }
        // ceil all
        if (target - (int)q.size() > 0) return "-1";
        
        int errors = 0;
        while (!q.empty()) {
            if (target > 0) {
                // ceil
                target -= 1;
                errors += 1000 - q.top();
            } else {
                // floor
                errors += q.top();
            }
            q.pop();
        }
        string s(to_string(errors % 1000).substr(0, 3));
        if (s.length() < 3) s = string(3 - s.length(), '0') + s;
        return to_string(errors / 1000) + "." + s;
    }
};