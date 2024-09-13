class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        // Process each query
        for (const auto& q : queries) {
            int xorSum = 0;
            // Calculate XOR for the range [q[0], q[1]]
            for (int i = q[0]; i <= q[1]; i++) {
                xorSum ^= arr[i];
            }
            result.push_back(xorSum);
        }
        return result;
    }
};