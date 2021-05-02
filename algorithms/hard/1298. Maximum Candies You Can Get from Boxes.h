// 1298. Maximum Candies You Can Get from Boxes
// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

// Runtime: 132 ms, faster than 23.53% of C++ online submissions for Maximum Candies You Can Get from Boxes.
// Memory Usage: 42.9 MB, less than 5.88% of C++ online submissions for Maximum Candies You Can Get from Boxes.
    
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int n = status.size();
        int ans = 0;
        vector<bool> visited(n);
        unordered_set<int> myKeys, myBoxes;
        for (int i : initialBoxes) {
            if (status[i]) 
                myKeys.insert(begin(keys[i]), end(keys[i]));
            myBoxes.insert(i);
        }
        bool flag = true;
        auto openBox = [&](int i, unordered_set<int>& remainKeys, unordered_set<int>& remainBoxes){
            if (status[i] || myKeys.count(i)) {
                myKeys.erase(i);
                if (visited[i]) return true;
                visited[i] = true;
                flag = true;
                // open box_i
                ans += candies[i];
                for (int k : keys[i]) {
                    if (visited[k]) continue;
                    remainKeys.insert(k);
                }
                for (int b : containedBoxes[i]) {
                    if (visited[b]) continue;
                    remainBoxes.insert(b);
                }
                return true;
            }
            return false;
        };
        while (flag) {
            flag = false;
            unordered_set<int> remainKeys, remainBoxes;
            for (int i : myBoxes) {
                if (openBox(i, remainKeys, remainBoxes)) 
                    continue;
                remainBoxes.insert(i);
            }
            myKeys.insert(begin(remainKeys), end(remainKeys));
            myBoxes = remainBoxes;
        }
        return ans;
    }
};