// 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/

// Runtime: 128 ms, faster than 35.72% of C++ online submissions for Maximum Units on a Truck.
// Memory Usage: 16.5 MB, less than 46.50% of C++ online submissions for Maximum Units on a Truck.
    
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [](const vector<int>& l, const vector<int>& r){
            return l[1] < r[1];
        });
        int ans = 0;
        while (truckSize > 0 && !boxTypes.empty()) {
            int count = boxTypes.back()[0];
            int units = boxTypes.back()[1];
            int k = min(count, truckSize);
            boxTypes.pop_back();
            truckSize -= k;
            ans += k * units;
        }
        return ans;
    }
};