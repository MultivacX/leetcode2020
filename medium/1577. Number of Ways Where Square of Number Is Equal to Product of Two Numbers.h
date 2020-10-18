// 1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

// Runtime: 40 ms, faster than 88.64% of C++ online submissions for Number of Ways Where Square of Number Is Equal to Product of Two Numbers.
// Memory Usage: 12.3 MB, less than 8.69% of C++ online submissions for Number of Ways Where Square of Number Is Equal to Product of Two Numbers.

class Solution {
    int count(unordered_map<int64_t, int>& m1, unordered_map<int64_t, int>& m2) {
        int ans = 0;
        for (auto it1 : m1) {
            auto n1 = it1.first * it1.first;
            auto c1 = it1.second;
            unordered_set<int64_t> visited;
            for (auto it2 : m2) {
                auto n2 = it2.first;
                if (visited.count(n2)) continue;
                auto v = n1 / n2;
                // cout << n1 << " = " << n2 << " * " << v << endl;
                if (n1 != n2 * v) continue;
                if (!m2.count(v)) continue;
                
                visited.insert(v);
                auto c2 = it2.second;
                if (n2 == v) ans += c1 * c2 * (c2 - 1) / 2;
                else ans += c1 * c2 * m2[v];
            }
        }
        return ans;
    }
    
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int64_t, int> m1;
        for (int i : nums1) ++m1[i];
        unordered_map<int64_t, int> m2;
        for (int i : nums2) ++m2[i];
        return count(m1, m2) + count(m2, m1);
    }
};