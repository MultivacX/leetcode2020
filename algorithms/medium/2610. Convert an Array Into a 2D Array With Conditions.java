class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Arrays.sort(nums);
        int max_l = 1;
        for (int i = 1, l = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                l++;
                max_l = Math.max(max_l, l);
            } else {
                l = 1;
            }
        }

        List<List<Integer>> res = new ArrayList<>(max_l);
        for (int i = 0; i < max_l; i++) {
            res.add(new ArrayList<>());
        }
        int row = 0;
        res.get(row).add(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                row++;
                if (row >= max_l) row = 0;
                res.get(row).add(nums[i]);
            } else {
                res.get(row).add(nums[i]);
            }
        }
        return res;
    }
}