class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};