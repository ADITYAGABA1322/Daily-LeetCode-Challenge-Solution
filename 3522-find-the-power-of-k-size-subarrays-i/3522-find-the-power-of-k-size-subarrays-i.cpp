#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        std::vector<int> results;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; ++i) {
            bool is_sorted_and_consecutive = true;
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] != nums[j - 1] + 1) {
                    is_sorted_and_consecutive = false;
                    break;
                }
            }
            if (is_sorted_and_consecutive) {
                results.push_back(*std::max_element(nums.begin() + i, nums.begin() + i + k));
            } else {
                results.push_back(-1);
            }
        }
        
        return results;
    }
};