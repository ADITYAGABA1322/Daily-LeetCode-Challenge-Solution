#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums, int lo, int hi) {
        int inc = 0, exc = 0;
        for (int i = lo; i <= hi; i++) {
            int new_inc = exc + nums[i];
            exc = max(exc, inc);
            inc = new_inc;
        }
        return max(inc, exc);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};