// 1269. Number of Ways to Stay in the Same Place After Some Steps

class Solution {
public:
    int numWays(int steps, int arrLen) {
        // left: '{', right: '}', stay: ' '
        // count('{') == count('}') -> [0, arrLen / 2]
        // count(' ') = arrLen - 2 * count('{')
        
        int ans = 1;
        int catalan_number = 1;
        for (int pairs = 1; pairs <= arrLen / 2; ++pairs) {
            int num_stay = arrLen - 2 * pairs;
            // ways(i pairs {}) * ways(insert num_stay spaces in 2 * i + 1 positions)
            ans = ans + catalan_number * insert_spaces(num_stay, 2 * i + 1);
            catalan_number = catalan_number * 2 * (2 * i + 1) / (i + 2);
        }
        return ans;
    }
    
    int insert_spaces(int spaces, int max_positions) {
        // todo
        return 1;
    }
};