// 1700. Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// Runtime: 4 ms, faster than 77.77% of C++ online submissions for Number of Students Unable to Eat Lunch.
// Memory Usage: 9.1 MB, less than 36.24% of C++ online submissions for Number of Students Unable to Eat Lunch.
    
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int N = students.size();
        queue<int> q;
        int i = 0;
        for (int j = 0; j < students.size(); ++j) {
            if (students[j] == sandwiches[i]) ++i;
            else q.push(students[j]);
        }
        while (i < N) {
            int size = q.size();
            for (int j = 0; j < size; ++j) {
                int s = q.front(); q.pop();
                if (s == sandwiches[i]) {
                    ++i;
                    break;
                }
                q.push(s);
            }
            if (size == q.size()) break;
        }
        return q.size();
    }
};