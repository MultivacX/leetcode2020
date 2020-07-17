// 1157. Online Majority Element In Subarray
// https://leetcode.com/problems/online-majority-element-in-subarray/

// Time Limit Exceeded
// 26 / 27 test cases passed.
class MajorityChecker {
    vector<int>& arr_;
    
public:
    MajorityChecker(vector<int>& arr) : arr_(arr) {
        
    }
    
    int query(int left, int right, int threshold) {
        int val = arr_[left];
        int cnt = 1;
        for (int i = left + 1; i <= right; ++i) {
            if (val == arr_[i]) {
                ++cnt;
            } else if (cnt == 0) {
                val = arr_[i];
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (val == arr_[i]) ++cnt;
            if (cnt >= threshold) return val;
        }
        return -1;
    }
};