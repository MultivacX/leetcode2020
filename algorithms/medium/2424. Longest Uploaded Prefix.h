// 2424. Longest Uploaded Prefix
// https://leetcode.com/problems/longest-uploaded-prefix/

// Runtime: 401 ms, faster than 97.66% of C++ online submissions for Longest Uploaded Prefix.
// Memory Usage: 161.1 MB, less than 50.18% of C++ online submissions for Longest Uploaded Prefix.

class LUPrefix
{
    vector<int> vs;
    int px{0};

public:
    LUPrefix(int n) : vs(n + 1)
    {
    }

    void upload(int video)
    {
        vs[video] = 1;
        while (px + 1 < vs.size() && vs[px + 1])
            ++px;
    }

    int longest()
    {
        return px;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */