class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount + 1,
                                     vector<long long>(factoryCount + 1, 0));

        // Initialize base cases
        for (int i = 0; i < robotCount; i++)
            dp[i][factoryCount] = 1e12;  // No factories left

        // Fill DP table bottom-up
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Option 1: Assign current robot to current factory
                long long assign =
                    abs(robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];

                // Option 2: Skip current factory for the current robot
                long long skip = dp[i][j + 1];

                dp[i][j] = min(assign, skip);  // Take the minimum option
            }
        }
        // Minimum distance starting from first robot and factory
        return dp[0][0];
    }
};