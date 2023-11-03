class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] N = new int[n];
        int[] R = new int[n];
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (++N[A[i] - 1] == 2) ++k;
            if (++N[B[i] - 1] == 2) ++k;
            R[i] = k;
        }
        return R;
    }
}