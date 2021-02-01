// 949. Largest Time for Given Digits

// Runtime: 4 ms, faster than 47.35% of C++ online submissions for Largest Time for Given Digits.
// Memory Usage: 9.8 MB, less than 10.00% of C++ online submissions for Largest Time for Given Digits.

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        priority_queue<string> times;
        int used = 0;
        string time;
        auto push = [&](int idx){ used |= 1 << idx; time.push_back(A[idx] + '0'); };
        auto pop = [&](int idx){ used ^= 1 << idx; time.pop_back(); };
        for (int i = 0; i < 4; ++i) {
            if (A[i] > 2) continue;
            push(i);
            for (int j = 0; j < 4; ++j) {
                if (1 << j & used) continue;
                if (A[i] == 2 && A[j] > 3) continue;
                push(j);
                for (int k = 0; k < 4; ++k) {
                    if (1 << k & used) continue;
                    if (A[k] > 5) continue;
                    push(k);
                    for (int l = 0; l < 4; ++l) {
                        if (1 << l & used) continue;
                        push(l);
                        times.push(time);
                        pop(l);
                    }    
                    pop(k);
                }
                pop(j);
            }
            pop(i);
        }
        if (times.empty()) return "";
        return times.top().substr(0, 2) + ":" + times.top().substr(2);
    }
};