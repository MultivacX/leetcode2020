// 353. Design Snake Game
// https://leetcode.com/problems/design-snake-game/

// Runtime: 268 ms, faster than 31.43% of C++ online submissions for Design Snake Game.
// Memory Usage: 75.4 MB, less than 41.56% of C++ online submissions for Design Snake Game.
    
class SnakeGame {
    int w;
    int h;
    vector<vector<int>>& f;
    int fid;
    list<pair<int, int>> snake;
    unordered_map<int, unordered_set<int>> m;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) 
    : w(width), h(height), f(food), fid(0) {
        snake.push_front({0, 0});
        m[0].insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int i = snake.front().first;
        int j = snake.front().second;
        int ni = i;
        int nj = j;
        
        if (direction == "U") --ni;
        else if (direction == "D") ++ni;
        else if (direction == "L") --nj;
        else ++nj;
        
        // cout << ni << '_' << nj << ":   ";
        // for (auto it = snake.rbegin(); it != snake.rend(); ++it)
        //     cout << it->first << '_' << it->second << ' ';
        // cout << endl;
        
        if (ni < 0 || ni >= h || nj < 0 || nj >= w)
            return -1;
        
        if (fid >= f.size() || f[fid][0] != ni || f[fid][1] != nj) {
            m[snake.back().first].erase(snake.back().second);
            snake.pop_back(); 
        } else ++fid;
        
        if (m.count(ni) && m[ni].count(nj))
            return -1;
        
        snake.push_front({ni, nj});
        m[ni].insert(nj);
        return fid <= f.size() ? fid : f.size();
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */