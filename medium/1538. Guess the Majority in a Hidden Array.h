// 1538. Guess the Majority in a Hidden Array

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        const int N = reader.length();
        
        int i = 0;
        int p = reader.query(i, i + 1, i + 2, i + 3);
        
        vector<pair<int, int>> v{{0, -1}, {0, -1}};
        int j = -1;
        if (p == 4) {
            v[0].first = 4;
            v[0].second = 0;
            j = 0;
        } else if (p == 2) {
            v[0].first = 3;
            v[1].first = 1;
            j = -1;
        } else {
            v[0].first = 2;
            v[1].first = 2;
            j = -1;
        }
        
        // 4 xxxx
        // 2 xxxy / xxyx / xyxx / yxxx
        // 0 xxyy / xyxy / xyyx
        for (i = 1; i + 3 < N; ++i) {
            // 4->4 nums[i-1,i+0,i+1,i+2,i+3]
            // 4->2 nums[i-1,i+0,i+1,i+2] != nums[i+3]
            
            // 2->4 nums[i-1] != nums[i+0,i+1,i+2,i+3]
            // 2->2 nums[i-1] == nums[i+3]
            // 2->0 nums[i-1] != nums[i+3]
            
            // 0->2 nums[i-1] != nums[i+3]
            // 0->0 nums[i-1] == nums[i+3]
            
            int q = reader.query(i, i + 1, i + 2, i + 3);
            if (p == 4) {
                if (q == 4) {
                    
                } else { // q == 2
                    
                }
            } else if (p == 2) {
                if (q == 4) {
                    
                } else if (q == 2) {
                    
                } else { // q == 0
                
                }
            } else {
                if (q == 2) {
                    
                } else { // q == 0
                
                }
            }
        }
        
    }
};