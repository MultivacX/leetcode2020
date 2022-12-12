// 2502. Design Memory Allocator
// https://leetcode.com/problems/design-memory-allocator/

struct Chunk
{
    Chunk(int s, int e)
        : start(s), end(e) {}

    int start;
    int end;

    int size()
    {
        return end - start + 1;
    }
};

class Allocator
{
    int N;
    bitset<1000> mems;
    unordered_map<int, vector<Chunk>> used;

public:
    Allocator(int n) : N(n)
    {
    }

    int allocate(int size, int mID)
    {
        for (int i = 0, s = 0; i < N; ++i)
        {
            if (mems[i])
            {
                s = 0;
                continue;
            }
            if (++s == size)
            {
                int start = i - size + 1;
                int end = i;
                used[mID].emplace_back(start, end);
                while (end >= start)
                    mems[end--] = 1;
                return start;
            }
        }

        return -1;
    }

    int free(int mID)
    {
        int res = 0;
        while (!used[mID].empty())
        {
            res += used[mID].back().size();
            for (int i = used[mID].back().start; i <= used[mID].back().end; ++i)
                mems[i] = 0;
            used[mID].pop_back();
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */