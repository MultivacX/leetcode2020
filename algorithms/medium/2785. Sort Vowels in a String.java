class Solution {
    public String sortVowels(String s) {
        StringBuilder sb = new StringBuilder(s);
        int[] k = new int[10];
        for (int i = 0; i < s.length(); i++) {
            char c = sb.charAt(i);
            int j = "AEIOUaeiou".indexOf(c);
            if (j >= 0) {
                k[j]++;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            int t = "AEIOUaeiou".indexOf(sb.charAt(i));
            if (t >= 0) {
                for (int j = 0; j < 10; j++) {
                    if (k[j] > 0) {
                        sb.setCharAt(i, "AEIOUaeiou".charAt(j));
                        k[j]--;
                        break;
                    }
                }
            }
        }

        return sb.toString();
    }
}