// 1654. Minimum Jumps to Reach Home
// https://leetcode.com/problems/minimum-jumps-to-reach-home/

// Runtime: 128 ms, faster than 36.54% of C++ online submissions for Minimum Jumps to Reach Home.
// Memory Usage: 25.2 MB, less than 33.49% of C++ online submissions for Minimum Jumps to Reach Home.

class Solution {
public:
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		unordered_set<int> forbidden_(forbidden.begin(), forbidden.end());

        unordered_set<int> forwards{0};
        unordered_set<int> backwards{0};

        int steps = 0;
        queue<int> q;
        q.push(0);
		while(!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int position = q.front() >> 1;
                if (position == x) return steps;

                bool backward = q.front() & 1;
                q.pop();

                // cout << position << ":" << backward << ", ";

                int fx = position + a;
                if (fx - b > x && a >= b) {}
                else if (fx <= 10000 && !forbidden_.count(fx) && !forwards.count(fx)) {
                    q.push(fx << 1);
                    forwards.insert(fx);
                }

                int bx = position - b;
                if (!backward && bx > 0 && !forbidden_.count(bx) && !backwards.count(bx)) {
                    q.push((bx << 1) | 1);
                    backwards.insert(bx);
                }
            }
            // cout << endl;
            ++steps;
		}
		return -1;
	}
};

// WA
/*class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbidden_(forbidden.begin(), forbidden.end());
        
        // position, from forward/backward

        unordered_map<int, int> visited;
        int steps = 0;
        unordered_map<int, int> m;
        m[0] = 0;

        auto isVisited = [&](int position, int from){
            return visited[position] & from;
        };
        
        while (!m.empty()) {
            unordered_map<int, int> t;
            for (auto it : m) {
                int position = it.first;
                if (position == x) return steps;
                int from = it.second;
                visited[position] |= from;
                
                cout << position << ":" << bitset<2>(from) << ", ";

                // forward
                int next = position + a;
                if (next > x + 5000) {}
                else if (next > x && a >= b) {}
                else if (forbidden_.count(next)) {}
                else if (isVisited(next, 1)) {}
                else t[next] |= 1;

                // backward
                int prev = position - b;
                if (from & 2) {}
                else if (prev <= 0) {}
                else if (forbidden_.count(prev)) {}
                else if (isVisited(prev, 2)) {}
                else t[prev] |= 2;
            }
            cout << endl;
            ++steps;
            m = t;
        }
        return -1;
    }
};*/
