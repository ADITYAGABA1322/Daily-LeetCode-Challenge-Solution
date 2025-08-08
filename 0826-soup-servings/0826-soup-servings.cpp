class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0; // acceptable approximation
        int N = (n + 24) / 25;    // scale to 25 mL units
        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));

        function<double(int,int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;
            double &res = memo[a][b];
            if (res >= 0.0) return res;
            res = 0.25 * (dfs(a - 4, b)
                        + dfs(a - 3, b - 1)
                        + dfs(a - 2, b - 2)
                        + dfs(a - 1, b - 3));
            return res;
        };

        return dfs(N, N);
    }
};