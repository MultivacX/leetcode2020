// 969. Pancake Sorting
// https://leetcode.com/problems/pancake-sorting/

// Runtime: 4 ms, faster than 94.98% of C++ online submissions for Pancake Sorting.
// Memory Usage: 11.1 MB, less than 89.71% of C++ online submissions for Pancake Sorting.

// Time Complexity: O(A.size()^2).
// Space Complexity: O(ans.size()).

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int size = A.size();
        int j = size - 1;
        while (size > 1) {
            if (A[size - 1] != size) {
                // cout << size << endl;
                for (int i = 0; i < size; ++i) {
                    if (A[i] == size) {
                        if (i > 0) {
                            reverse(begin(A), begin(A) + i + 1);
                            ans.push_back(i + 1);
                            // cout << i + 1 << ": "; for (int a : A) cout << a << " "; cout << endl;
                        }

                        reverse(begin(A), begin(A) + size);
                        ans.push_back(size);
                        // cout << size << ": "; for (int a : A) cout << a << " "; cout << endl << endl;

                        break;
                    }
                }
            }
            --size;
        }
        return ans;
    }
};