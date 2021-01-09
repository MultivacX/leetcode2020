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
        static const int s40 = 4;
        static const int s31 = 2;
        static const int s22 = 0;
        const int N = reader.length();
        
        int i = 0;
        int p = reader.query(i, i + 1, i + 2, i + 3);
        
        int cnt1 = 0; unordered_set<int> idx1;
        int cnt2 = 0; unordered_set<int> idx2;
        int* pre_max = nullptr;
        if (p == s40) {
            cnt1 = 4, idx1 = unordered_set<int>{0, 1, 2, 3};
            cnt2 = 0;
        } else if (p == s31) {
            cnt1 = 3;
            cnt2 = 1;
        } else {
            cnt1 = 2;
            cnt2 = 2;
        }
        
        // s40 xxxx
        // s31 xxxy / xxyx / xyxx / yxxx
        // s22 xxyy / xyxy / xyyx
        for (i = 1; i + 3 < N; ++i) {
            // 40->40 nums[i-1,i+0,i+1,i+2,i+3]
            // 40->31 nums[i-1,i+0,i+1,i+2] != nums[i+3]
            
            // 31->40 nums[i-1] != nums[i+0,i+1,i+2,i+3]
            // 31->31 nums[i-1] == nums[i+3]
            // 31->22 nums[i-1] != nums[i+3]
            
            // 22->31 nums[i-1] != nums[i+3]
            // 22->22 nums[i-1] == nums[i+3]
            
            int q = reader.query(i, i + 1, i + 2, i + 3);
            int pre = i - 1, nxt = i + 3;
            
            if (p == s40 && q == s40) {
                if (idx1.count(pre)) cnt1 += 1, idx1.insert(nxt);
                else cnt2 += 1, idx2.insert(nxt);
            } else if (p == s40 && q == s31) {
                if (idx1.count(pre)) cnt2 += 1, idx2.insert(nxt);
                else cnt1 += 1, idx1.insert(nxt);
            } 
            // TODO
            else if (p == s31 && q == s40) {
                if (idx1.count(pre)) cnt2 += 1, idx2.insert(nxt);
                else cnt1 += 1, idx1.insert(nxt);
            } else if (p == s31 && q == s31) {
                if (idx1.count(pre)) cnt1 += 1, idx1.insert(nxt);
                else cnt2 += 1, idx2.insert(nxt);
            } else if (p == s31 && q == s22) {
                if (idx1.count(pre)) cnt2 += 1, idx2.insert(nxt);
                else cnt1 += 1, idx1.insert(nxt);
            } 
            
            else if (p == s22 && q == s31) {
                if (idx1.count(pre)) cnt2 += 1, idx2.insert(nxt);
                else cnt1 += 1, idx1.insert(nxt);
            } else {
                if (idx1.count(pre)) cnt1 += 1, idx1.insert(nxt);
                else cnt2 += 1, idx2.insert(nxt);
            }
        }
        if  (cnt1 == cnt2) return -1;
        return cnt1 > cnt2 ? *idx1.begin() : *idx2.begin();
    }
};