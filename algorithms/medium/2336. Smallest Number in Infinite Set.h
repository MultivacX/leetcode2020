// 2336. Smallest Number in Infinite Set
// https://leetcode.com/problems/smallest-number-in-infinite-set/

// Runtime: 133 ms, faster than 72.32% of C++ online submissions for Smallest Number in Infinite Set.
// Memory Usage: 46.3 MB, less than 11.35% of C++ online submissions for Smallest Number in Infinite Set.

class SmallestInfiniteSet
{
public:
    set<int> nums;

    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; ++i)
            nums.insert(i);
    }

    int popSmallest()
    {
        int res = *nums.begin();
        nums.erase(res);
        return res;
    }

    void addBack(int num)
    {
        nums.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */