class Solution {
    public long[] findPrefixScore(int[] nums) {
        int N = nums.length;

        long conver = nums[0];
        long max = nums[0];

        long[] score = new long[N];
        score[0] = conver + max;

        for (int i = 1; i < N; i++) {
            if (max < nums[i]) max = nums[i];
            conver = nums[i] + max;

            score[i] = score[i - 1] + conver;
        }

        return score;
    }
}