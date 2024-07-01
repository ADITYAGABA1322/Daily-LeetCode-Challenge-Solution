#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefixSum;
    vector<int> originalNums;

public:
    NumArray(vector<int>& nums) {
        originalNums = nums;
        prefixSum.resize(nums.size());
        if (!nums.empty()) {
            prefixSum[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
        }
    }
    
    void update(int index, int val) {
        int diff = val - originalNums[index];
        originalNums[index] = val;
        for (int i = index; i < originalNums.size(); ++i) {
            prefixSum[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};