// 1079. Letter Tile Possibilities

// Runtime: 12 ms, faster than 62.07% of C++ online submissions for Letter Tile Possibilities.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Letter Tile Possibilities.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(begin(tiles), end(tiles));
        int ans = 0;
        for (int i = 1; i <= tiles.length(); ++i) {
            int visited = 0;
            ans += count(tiles, visited, i);
        }
        return ans;
    }
    
    int count(const string& tiles, int& visited, int length) {
        if (length == 0) {
            cout << endl;
            return 1;
        }
        
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < tiles.length(); ++i) {
            if (visited & (1 << i)) continue;
            if (cur & (1 << (tiles[i] - 'A'))) continue;
            cur |= 1 << (tiles[i] - 'A');
            // cout << tiles[i];
            visited |= 1 << i;
            ans += count(tiles, visited, length - 1);
            visited ^= 1 << i;
        }
        return ans;
    }
};