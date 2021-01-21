// 1491. Average Salary Excluding the Minimum and Maximum Salary
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
// Memory Usage: 7.1 MB, less than 97.02% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
    
class Solution {
public:
    double average(vector<int>& salary) {
        const int N = salary.size();
        int sum = salary[0];
        int minv = salary[0];
        int maxv = salary[0];
        for (int i = 1; i < N; ++i) {
            sum += salary[i];
            if (minv > salary[i])
                minv = salary[i];
            if (maxv < salary[i])
                maxv = salary[i];
        }
        return (sum - minv - maxv) / (double)(N - 2);
    }
};