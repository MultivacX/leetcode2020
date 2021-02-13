// 1. Two Sum

// Runtime: 136 ms, faster than 31.68% of C++ online submissions for Two Sum.
// Memory Usage: 9.2 MB, less than 96.19% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) return {i, j};
            }    
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]].push_back(i);
        for (const auto& it : m) {
            int a = it.first;
            int b = target - a;
            if (a == b) {
                if (it.second.size() > 1)
                    return {it.second[0], it.second[1]};
            } else if (m.count(b)) {
                return {it.second[0], m[b][0]};
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int b = target - nums[i];
            if (m.count(b)) return {m[b], i};
            m[b] = i;
        }
        return {};
    }
};