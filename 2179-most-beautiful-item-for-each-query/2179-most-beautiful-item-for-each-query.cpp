class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items based on their prices
        sort(items.begin(), items.end());

        // Create a vector of pairs to keep track of original indices of queries
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        // Sort queries based on their values
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size());
        int maxBeauty = 0;
        int j = 0;

        // Traverse the sorted queries
        for (const auto& query : sortedQueries) {
            int queryPrice = query.first;
            int queryIndex = query.second;

            // Move the pointer to include all items with prices <= queryPrice
            while (j < items.size() && items[j][0] <= queryPrice) {
                maxBeauty = max(maxBeauty, items[j][1]);
                ++j;
            }

            // Store the result for the current query
            result[queryIndex] = maxBeauty;
        }

        return result;
    }
};