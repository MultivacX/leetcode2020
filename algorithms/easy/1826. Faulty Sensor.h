// 1826. Faulty Sensor
// https://leetcode.com/problems/faulty-sensor/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Faulty Sensor.
// Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Faulty Sensor.
    
class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        const int n = sensor1.size();
        
        int i = 0, j = -1;
        for (; i < n && j == -1; ++i) 
            if (sensor1[i] != sensor2[i])
                j = i;
        if (j == -1 || j == n - 1) return -1;
        
        i = j;
        while (i + 1 < n && sensor1[i] == sensor2[i + 1])
            ++i;
        if (i == n - 1) return 1; 
        
        i = j;
        while (i + 1 < n && sensor1[i + 1] == sensor2[i])
            ++i;
        if (i == n - 1) return 2;
        
        return -1;
    }
};