// 1093. Statistics from a Large Sample
// https://leetcode.com/problems/statistics-from-a-large-sample/

// Runtime: 8 ms, faster than 29.71% of C++ online submissions for Statistics from a Large Sample.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Statistics from a Large Sample.

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = -1;
        double maximum = 0;
        
        double mean = 0;
        int cnt = 0;
        double sum = 0;
        
        double mode = 0;
        
        for (int i = 0; i < 256; ++i) {
            if (count[i] == 0) continue;
            
            if (minimum < 0) minimum = i;
            maximum = i;
            
            cnt += count[i];
            sum += count[i] * i;
            
            if (count[i] > count[mode]) mode = i;
        }
        
        mean = sum / cnt;
        
        double median = -1;
        int k = 0;
        for (int i = 0; i < 256; ++i) {
            if (count[i] == 0) continue;
            k += count[i];
            if (cnt & 1) {
                if (k * 2 >= cnt) {
                    median = i;
                    break;
                }
            } else if (k * 2 == cnt) {
                median = i;
            } else if (k * 2 > cnt) {
                if (median < 0) median = i;
                else median = (median + i) / 2.0;
                break;
            }
        }
        
        return {minimum, maximum, mean, median, mode};
    }
};