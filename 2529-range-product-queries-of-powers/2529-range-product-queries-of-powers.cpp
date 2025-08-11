class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int cur = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                cur = static_cast<long long>(cur) * bins[i] % mod;
            }
            ans.push_back(cur);
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};