// 493. Reverse Pairs

// Runtime: 348 ms, faster than 47.94% of C++ online submissions for Reverse Pairs.
// Memory Usage: 72.8 MB, less than 36.36% of C++ online submissions for Reverse Pairs.

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        merge_sort(nums, 0, nums.size(), ans);
        return ans;
    }
    
    void merge_sort(vector<int>& nums, int begin, int end, int& ans) {
        if (begin >= end - 1) return;
        
        int mid = begin + (end - begin) / 2;
        merge_sort(nums, begin, mid, ans);
        merge_sort(nums, mid, end, ans);
        // for (int i = begin; i < mid; ++i) printf("[%d]=%d, ", i, nums[i]);
        // cout << endl;
        // for (int i = mid; i < end; ++i) printf("[%d]=%d, ", i, nums[i]);
        // cout << endl << endl;
        int j = mid;
        for (int i = begin; i < mid; ++i) {
            while (j < end && (int64_t)nums[i] > (int64_t)nums[j] * 2) 
                ++j;
            ans += j - mid;
        }
        inplace_merge(nums.begin() + begin, nums.begin() + mid, nums.begin() + end);
    }
};

// Time Limit Exceeded
// 37 / 137 test cases passed.
/*class XTreeNode {
public:
    XTreeNode(int64_t v) : val(v) {}
    int64_t val;
    int count{1};
    int smaller{0};
    int greater{0};
    XTreeNode* left{nullptr};
    XTreeNode* right{nullptr};
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        int ans = 0;
        XTreeNode* root = new XTreeNode((int64_t)nums[n - 1] * 2);
        for (int i = n - 2; i >= 0; --i) {
            ans += find(root, nums[i]);
            insert(root, (int64_t)nums[i] * 2);
        }
        // deque<XTreeNode*> q;
        // q.push_back(root);
        // while (!q.empty()) {
        //     int size = q.size();
        //     while (size--) {
        //         auto node = q.front();
        //         printf("(%d, %d, %d, %d) ", node->val, node->count, node->smaller, node->greater);
        //         q.pop_front();
        //         if (node->left) q.push_back(node->left);
        //         if (node->right) q.push_back(node->right);
        //     }
        //     cout << endl;
        // }
        return ans;
    }
    
    int find(XTreeNode* root, int64_t val) {
        if (!root) {
            return 0;
        } else if (val < root->val) {
            return find(root->left, val);
        } else if (val > root->val) {
            return root->count + root->smaller + find(root->right, val);
        } else {
            return root->smaller;
        }
    }
    
    XTreeNode* insert(XTreeNode* root, int64_t val) {
        if (!root) {
            return new XTreeNode(val);
        } else if (val < root->val) {
            ++root->smaller;
            root->left = insert(root->left, val);
        } else if (val > root->val) {
            ++root->greater;
            root->right = insert(root->right, val);
        } else {
            ++root->count;
        }
        return root;
    }
};*/

// Time Limit Exceeded
// 35 / 137 test cases passed.
/*class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        int ans = 0;
        vector<int64_t> s{(int64_t)nums[n - 1] * 2};
        for (int i = n - 2; i >= 0; --i) {
            auto it = lower_bound(s.begin(), s.end(), nums[i]);
            ans += it - s.begin();
            it = lower_bound(s.begin(), s.end(), (int64_t)nums[i] * 2);
            s.emplace(it, (int64_t)nums[i] * 2);
        }
        return ans;
    }
};*/