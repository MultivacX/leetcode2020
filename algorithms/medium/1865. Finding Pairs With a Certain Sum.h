// 1865. Finding Pairs With a Certain Sum
// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

// Runtime: 260 ms, faster than 95.33% of C++ online submissions for Finding Pairs With a Certain Sum.
// Memory Usage: 72.2 MB, less than 98.81% of C++ online submissions for Finding Pairs With a Certain Sum.
    
class FindSumPairs {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    vector<int>& n2;
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : n2(nums2) {
        for (int i : nums1) ++m1[i];
        for (int i : nums2) ++m2[i];
    }
    
    void add(int index, int val) {
        if (--m2[n2[index]] == 0) 
            m2.erase(n2[index]);
        
        n2[index] += val;
        ++m2[n2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (const auto& [v, k] : m1) 
            if (m2.count(tot - v))
                ans += k * m2[tot - v];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */