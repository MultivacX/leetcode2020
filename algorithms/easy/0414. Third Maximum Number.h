// 414. Third Maximum Number

// Runtime: 4 ms, faster than 98.96% of C++ online submissions for Third Maximum Number.
// Memory Usage: 9.2 MB, less than 46.15% of C++ online submissions for Third Maximum Number.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int64_t _max = (int64_t)INT_MIN - 1;
        for (int num : nums) 
            _max = max(_max, (int64_t)num);
        
        int64_t _mid = (int64_t)INT_MIN - 1;
        for (int num : nums) 
            if (num != _max)
                _mid = max(_mid, (int64_t)num);
        
        int64_t _min = (int64_t)INT_MIN - 1;
        for (int num : nums) 
            if (num != _max && num != _mid)
                _min = max(_min, (int64_t)num);
        
        // printf("%lld, %lld, %lld\n", _min, _mid, _max);
        
        if (_min != (int64_t)INT_MIN - 1) return _min;
        // if (_mid != INT_MIN) return _max;
        return _max;
    }
};