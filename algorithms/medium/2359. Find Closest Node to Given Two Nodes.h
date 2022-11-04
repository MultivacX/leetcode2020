// 2359. Find Closest Node to Given Two Nodes
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

// Runtime: 477 ms, faster than 43.65% of C++ online submissions for Find Closest Node to Given Two Nodes.
// Memory Usage: 91.1 MB, less than 92.36% of C++ online submissions for Find Closest Node to Given Two Nodes.

class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        queue<int> q1, q2;
        q1.push(node1);
        q2.push(node2);
        const int n = edges.size();
        static const int visitFrom1 = 100001;
        static const int visitFrom2 = 100002;
        static const int visited = 100003;
        while (!q1.empty() || !q2.empty())
        {
            int res = INT_MAX;

            int n1 = q1.size();
            while (n1 > 0)
            {
                --n1;
                int node = q1.front();
                q1.pop();
                if (0 <= edges[node] && edges[node] < n)
                {
                    q1.push(edges[node]);
                    edges[node] = visitFrom1;
                }
                else if (edges[node] == -1)
                {
                    edges[node] = visitFrom1;
                }
                else if (edges[node] == visitFrom2)
                {
                    res = min(res, node);
                    edges[node] = visited;
                }
            }

            int n2 = q2.size();
            while (n2 > 0)
            {
                --n2;
                int node = q2.front();
                q2.pop();
                if (0 <= edges[node] && edges[node] < n)
                {
                    q2.push(edges[node]);
                    edges[node] = visitFrom2;
                }
                else if (edges[node] == -1)
                {
                    edges[node] = visitFrom2;
                }
                else if (edges[node] == visitFrom1)
                {
                    res = min(res, node);
                    edges[node] = visited;
                }
            }

            // cout << res << endl;
            if (res != INT_MAX)
                return res;
        }

        // for (int i : edges) cout << i << ' '; cout << endl;

        return -1;
    }
};