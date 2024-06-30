class Solution {
    public String shortestPalindrome(String s) {
        // 1.) Using KMP Algorithm
        String r = new StringBuilder(s).reverse().toString();
        String t = s + "#" + r;
        int n = t.length();
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && t.charAt(i) != t.charAt(j)) j = p[j - 1];
            if (t.charAt(i) == t.charAt(j)) j++;
            p[i] = j;
        }
        return new StringBuilder(r.substring(0, s.length() - p[n - 1])).append(s).toString();
    }
}