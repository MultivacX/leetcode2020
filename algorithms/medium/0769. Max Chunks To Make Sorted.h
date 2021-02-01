// 769. Max Chunks To Make Sorted

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Chunks To Make Sorted.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Max Chunks To Make Sorted.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        if (n <= 1) return 1;
        
        int cnt = 0;
        int max_num_of_cur_chunk = -1;
        for (int i = 0; i < n; ++i) {
            if (max_num_of_cur_chunk == -1) {
                ++cnt;
                if (i != arr[i])
                    max_num_of_cur_chunk = arr[i];
                continue;
            }
            
            if (max_num_of_cur_chunk < arr[i])
                max_num_of_cur_chunk = arr[i];
            else if (max_num_of_cur_chunk == i)
                max_num_of_cur_chunk = -1;
        }
        return cnt;
    }
};