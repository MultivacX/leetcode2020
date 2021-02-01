// 768. Max Chunks To Make Sorted II

// Runtime: 12 ms, faster than 80.85% of C++ online submissions for Max Chunks To Make Sorted II.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Max Chunks To Make Sorted II.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        list<int> l{0};
        for (int i = 1; i < arr.size(); ++i) {
            int k = l.back();
            if (arr[i] < arr[k]) {
                // erase j : arr[j] > arr[i], j = [l.begin, l.end - 1)
                // l.remove_if([&](int j){ return j != k && arr[j] > arr[i]; });
                auto it = l.rbegin();
                ++it;
                while (it != l.rend() && arr[*it] > arr[i]) {
                    l.remove(*it);
                    it = l.rbegin();
                    ++it;
                }
            } else {
                l.push_back(i);
            }
        }
        return l.size();
    }
};