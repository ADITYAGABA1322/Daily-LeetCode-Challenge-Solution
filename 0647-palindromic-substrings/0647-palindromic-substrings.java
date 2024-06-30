class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int count = 0;
        int[][] dp = new int[n][n];

        for (int gap = 0; gap < n; gap++) {
            for (int l = 0, h = gap; h < n; l++, h++) {
                if (l == h) {
                    dp[l][h] = 1;
                } else if (l + 1 == h) {
                    dp[l][h] = (s.charAt(l) == s.charAt(h)) ? 1 : 0;
                } else {
                    dp[l][h] = (s.charAt(l) == s.charAt(h)) ? dp[l + 1][h - 1] : 0;
                }

                count += dp[l][h];
            }
        }

        return count;
    }
}

// int count = 0;

        // for (int center = 0; center <= 2 * n - 1; ++center) {
        //     int left = center / 2;
        //     int right = left + center % 2;

        //     while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
        //         count++;
        //         left--;
        //         right++;
        //     }
        // }

        // return count;