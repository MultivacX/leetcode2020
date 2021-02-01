// 489. Robot Room Cleaner
// https://leetcode.com/problems/robot-room-cleaner/

// Runtime: 16 ms, faster than 76.48% of C++ online submissions for Robot Room Cleaner.
// Memory Usage: 8.9 MB, less than 84.63% of C++ online submissions for Robot Room Cleaner.
    
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    const vector<vector<int>> D{
        // up   right    down     left
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}  
    };
    unordered_map<int, unordered_set<int>> visited;
    
    void moveBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void clean(Robot& robot, int x, int y, int d) {
        // cout << x << ", " << y << endl;
        visited[x].insert(y);
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int nd = (d + i) % 4;
            int nx = x + D[nd][0];
            int ny = y + D[nd][1];
            if ((visited.count(nx) == 0 || visited[nx].count(ny) == 0) && robot.move()) {
                clean(robot, nx, ny, nd);
                moveBack(robot);
            }
            robot.turnRight();
        }
    }
    
public:
    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0);
    }
};