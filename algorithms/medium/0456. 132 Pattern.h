// 456. 132 Pattern

// Runtime: 40 ms, faster than 36.38% of C++ online submissions for 132 Pattern.
// Memory Usage: 12.6 MB, less than 25.00% of C++ online submissions for 132 Pattern.

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return false;
        
        vector<int> min_nums{nums[0]};
        for (int i = 1; i < n - 2; ++i) 
            min_nums.push_back(min(min_nums.back(), nums[i]));
        
        set<int> s;
        s.insert(nums[n - 1]);
        for (int j = n - 2; j > 0; --j) {
            auto it = s.insert(nums[j]).first;
            if (it == s.begin()) continue;
            --it;
            int ak = *it;
            int aj = nums[j];
            int ai = min_nums[j - 1];
            if (ai < ak && ak < aj) return true;
        }
        
        return false;
    }
};

// Runtime: 44 ms
// Memory Usage: 14 MB
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return false;
        
        map<int, int> m;
        for (int k = 2; k < N; ++k) ++m[nums[k]];
        
        for (int i = 0, j = 1; j < N - 1; ++j) {
            if (j >= 2 && --m[nums[j]] == 0) 
                m.erase(nums[j]); 
            
            if (nums[i] < nums[j]) {
                auto it = m.upper_bound(nums[i]);
                if (it != m.end() && it->first < nums[j]) 
                    return true;
            } else {
                i = j;
            }
        }
        return false;
    }
};