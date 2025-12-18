class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long actualProfit = 0;

        vector<long long> profit(n);
        for (int i = 0; i < n; i++) {
            profit[i] = 1LL * prices[i] * strategy[i];
            actualProfit += profit[i];
        }

        long long maxGain = 0;
        long long originalPro = 0;
        long long modifyPro = 0;

        int i = 0;
        for (int j = 0; j < n; j++) {

            // original window profit
            originalPro += profit[j];

            // modified window profit (second half only)
            if (j - i + 1 > k / 2) {
                modifyPro += prices[j];  // force to 1
            }

            // shrink window
            if (j - i + 1 > k) {
                originalPro -= profit[i];
                if (i + k / 2 <= j) {
                    modifyPro -= prices[i + k / 2];
                }
                i++;
            }

            // evaluate
            if (j - i + 1 == k) {
                maxGain = max(maxGain, modifyPro - originalPro);
            }
        }

        return actualProfit + maxGain;
    }
};