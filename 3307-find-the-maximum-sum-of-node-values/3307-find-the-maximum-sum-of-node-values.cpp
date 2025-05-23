class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

private:
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                            vector<vector<long long>>& memo) {
        if (index == nums.size()) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long long noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long long xorDone = (nums[index] ^ k) +
                            maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};