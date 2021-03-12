// 46. Permutations

// Runtime: 8 ms, faster than 98.87% of C++ online submissions for Permutations.
// Memory Usage: 9.1 MB, less than 98.51% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0)
            return {};
        
        int cnt = 1;
        // vector<int> idx(n, 0);
        for (int i = 0; i < n; ++i) {
            cnt *= i + 1;
            // idx[i] = i;
        }
        
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
            
            int i = n - 1;
            while (i >= 1) {
                if (nums[i - 1] < nums[i]) {
                    int j = n - 1;
                    while (nums[j] < nums[i - 1]) 
                        --j;
                    swap(nums[j], nums[i - 1]);
                    
                    j = n - 1;
                    while (i < j) 
                        swap(nums[i++], nums[j--]);
                    
                    break;
                }
                --i;
            }
            if (i == 0) {
                int j = n - 1;
                while (i < j) 
                    swap(nums[i++], nums[j--]);
            }
            --cnt;
        } while (cnt > 0);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        int k = 1;
        for (int i = 2; i <= n; ++i) k *= i;
        vector<vector<int>> ans{nums};
        while (--k > 0) {
            auto cur = ans.back();
            int j = n - 1;
            while (j > 0 && cur[j - 1] > cur[j]) --j;
            if (j == 0) {
                reverse(begin(cur), end(cur));
            } else {
                // [j, n - 1]
                int i = n - 1;
                while (cur[j - 1] > cur[i]) --i;
                swap(cur[j - 1], cur[i]);
                reverse(begin(cur) + j, end(cur));
            }
            ans.push_back(move(cur));
        }
        return ans;
    }
};