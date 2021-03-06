// 162. Find Peak Element

// Runtime: 4 ms, faster than 96.62% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.5 MB, less than 95.45% of C++ online submissions for Find Peak Element.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        int begin = 0;
        int end = n;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            bool is_greater_than_left = mid - 1 < 0 ? true : nums[mid] > nums[mid - 1];
            bool is_greater_than_right = mid + 1 >= n ? true : nums[mid] > nums[mid + 1];
            if (is_greater_than_left && is_greater_than_right) return mid;
            else if (is_greater_than_left) begin = mid + 1;
            else end = mid;
        }
        return -1;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            int64_t lv = m > 0 ? nums[m - 1] : (int64_t)INT_MIN - 1;
            int64_t mv = nums[m];
            int64_t rv = m + 1 < n ? nums[m + 1] : (int64_t)INT_MIN - 1;
            if (lv < mv && mv > rv) return m;
            // cout << l << " " << m << " " << r << endl;
            if (lv > mv) r = m;
            else l = m + 1;
        }
        return l;
    }
};