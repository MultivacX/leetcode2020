// 458. Poor Pigs
// https://leetcode.com/problems/poor-pigs/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Poor Pigs.
// Memory Usage: 6.2 MB, less than 43.48% of C++ online submissions for Poor Pigs.

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Entropy: 
        
        // H(POISON_BUCKET) = -1 * sum(pi * log2(pi))
        // pi = 1 / buckets
        // i = [0, buckets)
        
        int k = minutesToTest / minutesToDie + 1;
        // every pig has k states
        // there are n pigs
        // all_states = pow(k, n)
        // H(PIG_WILL_DIE) = -1 * sum(pi * log2(pi))
        // pi = 1 / all_states
        // i = [0, n)
        
        // H(PIG_WILL_DIE) >= H(POISON_BUCKET)
        
        return ceil(log(buckets) / log(k));
    }
};