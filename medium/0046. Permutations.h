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