// 1654. Minimum Jumps to Reach Home
// https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		unordered_set<int> forbi(forbidden.begin(), forbidden.end());
		vector<vector<int>> visited(2,vector<int>(5000));
		// visited array has two states:
		// visited[0][i] means the ith cell was reached from its left hand side jumping forward, 
		// visited[1][i] means the ith cell was reached from its right hand side jumping backward. 
		queue<pair<int,bool>> qu; 
		// true means your last jump was backward jumping, you cannot jump backward in current step.
		// false, otherwise.
		qu.push({0,false});
		visited[0][0] = 1;
		visited[1][0] = 1;
		int ans = 0;
		while(!qu.empty()) {
			int len = qu.size();
			while(len > 0) {
				len--;
				int cur = qu.front().first;
				bool flag = qu.front().second;
                cout << cur << ":" << flag << ", ";
				if(cur == x) {
					return ans;
				}
				qu.pop();
				int forward = cur + a;
				int backward = cur - b;
				if(forward < 5000 && visited[0][forward] == 0 && !forbi.count(forward)) {
					qu.push({forward,false});
					visited[0][forward] = 1;
				}
				if(backward >=0 && visited[1][backward] == 0 && !forbi.count(backward) && !flag) {
					qu.push({backward,true});
					visited[1][backward] = 1;
				}
			}
            cout << endl;
			ans++;
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
