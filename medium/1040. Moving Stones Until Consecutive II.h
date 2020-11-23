// 1040. Moving Stones Until Consecutive II
// https://leetcode.com/problems/moving-stones-until-consecutive-ii/

// Runtime: 64 ms, faster than 6.09% of C++ online submissions for Moving Stones Until Consecutive II.
// Memory Usage: 13.1 MB, less than 13.91% of C++ online submissions for Moving Stones Until Consecutive II.
    
class Solution {
    void move(vector<int>& stones, vector<int>& prefix, int& min_moves, int& max_moves) {
        const int N = stones.size();

        // for (int i = 0; i < N; ++i) {
        //     cout << stones[i];
        //     if (i + 1 != N && stones[i] != stones[i + 1] - 1)
        //         cout << " <" << stones[i + 1] - stones[i] - 1 << ">";
        //     cout << ' ';
        // } cout << endl;

        prefix[0] = 0;
        for (int i = 1; i < N; ++i) 
            prefix[i] = prefix[i - 1] + stones[i] - stones[i - 1] - 1;

        for (int i = 0; i < N; ++i) {
            int leftStones = i;
            int rightStones = N - 1 - i;
            int unoccupied = prefix.back() - prefix[i];
            // cout << i << " :  L" << leftStones << " [" << stones[i] << "] <" << unoccupied << "> R" << rightStones << endl;

            // stones[i] as left endpoint
            // move stones[0,..,i-1] to stones[i]'s rightside
            int moves = 0;
            if (unoccupied == leftStones) {
                moves = leftStones;
            } else if (unoccupied < leftStones || 
                       (leftStones == 0 && unoccupied == stones[N - 1] - stones[N - 2] - 1)) {
                continue;
            } else {
                int maxStoneAfterMoves = stones[i] + leftStones + rightStones;
                int cnt = end(stones) - upper_bound(begin(stones) + i, end(stones), maxStoneAfterMoves);
                moves = leftStones + cnt;
                // cout << "    " << stones[i] << "..." << maxStoneAfterMoves << endl;
            }
            // cout << "    " << moves << endl;
            
            min_moves = min(min_moves, moves);
        }
        
        max_moves = max(max_moves, prefix[N - 1] - (stones[0] + 1 != stones[1] ? prefix[1] : 0));
        max_moves = max(max_moves, stones[N - 2] + 1 != stones[N - 1] ? prefix[N - 2] : prefix[N - 1]);
    }

public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        const int N = stones.size();
        sort(begin(stones), end(stones));
        vector<int> prefix(N, 0);
        int min_moves = INT_MAX, max_moves = INT_MIN;
        move(stones, prefix, min_moves, max_moves);

        int i = 0, j = N - 1;
        while (i <= j) {
            stones[i] *= -1;
            if (i != j) stones[j] *= -1;
            swap(stones[i++], stones[j--]);
        }
        move(stones, prefix, min_moves, max_moves);

        return {min_moves, max_moves};
    }
};