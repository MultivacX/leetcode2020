// 1985. Find the Kth Largest Integer in the Array
// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

// Runtime: 597 ms, faster than 32.92% of C++ online submissions for Find the Kth Largest Integer in the Array.
// Memory Usage: 88.6 MB, less than 38.72% of C++ online submissions for Find the Kth Largest Integer in the Array.
    
class Solution {
public:
    /*string kthLargestNumber(vector<string>& nums, int k) {
        const int n = nums.size();
        sort(begin(nums), end(nums), [&](const string& l, const string& r){
            const int ll = l.length();
            const int rl = r.length();
            if (ll == rl) {
                if (l == r) return true;
                for (int i = 0; i < ll; ++i) {
                    if (l[i] == r[i]) continue;
                    return l[i] < r[i] ? true : false;        
                }
            } 
            return ll < rl ? true : false;
        });
        return nums[n - k];
    }*/
    
    string kthLargestNumber(vector<string>& nums, int k) {
        unordered_map<string, int> m;
        for (auto& s : nums) ++m[s];
        
        vector<string> v;
        for (auto& it : m) v.push_back(it.first);
        sort(begin(v), end(v), [](const string& l, const string& r){
            const int ll = l.length();
            const int rl = r.length();
            if (ll == rl) {
                if (l == r) return true;
                for (int i = 0; i < ll; ++i) {
                    if (l[i] == r[i]) continue;
                    return l[i] < r[i] ? true : false;        
                }
            } 
            return ll < rl ? true : false;
        });
        
        for (int i = v.size() - 1; i >= 0 && k > 0; --i) {
            k -= m[v[i]];
            if (k <= 0) return v[i];
        }
        return "";
    }
};