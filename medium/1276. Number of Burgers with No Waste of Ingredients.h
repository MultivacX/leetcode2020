// 1276. Number of Burgers with No Waste of Ingredients
// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/

// Runtime: 4 ms, faster than 81.47% of C++ online submissions for Number of Burgers with No Waste of Ingredients.
// Memory Usage: 7.7 MB, less than 35.46% of C++ online submissions for Number of Burgers with No Waste of Ingredients.

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // j * 4 + s * 2 = tomatoSlices
        // j * 1 + s * 1 = cheeseSlices
        int j = (tomatoSlices - cheeseSlices * 2) / 2;
        int s = cheeseSlices - j;
        // cout << j << ", " << s << endl;
        if (j >= 0 && s >= 0 && 
            j * 4 + s * 2 == tomatoSlices &&
            j * 1 + s * 1 == cheeseSlices)
            return vector<int>{j, s};
        return vector<int>{};
    }
};