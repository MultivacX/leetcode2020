class Solution {
    public int matrixSum(int[][] nums) {
        int R = nums.length;
        for (int i = 0; i < R; ++i)
            Arrays.sort(nums[i]);
        
        int res = 0;
        int C = nums[0].length;
        
        for (int j = C - 1; j >= 0; --j) {
            int max = nums[0][j];
            for (int i = 1; i < R; ++i) {
                max = Math.max(max, nums[i][j]);
            }
            res += max;
        }
        
        return res;
    }
}