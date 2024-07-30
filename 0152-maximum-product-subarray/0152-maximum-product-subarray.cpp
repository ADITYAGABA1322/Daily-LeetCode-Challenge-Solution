#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prod = 1.0;
        double res = static_cast<double>(INT_MIN);
        
        // Forward pass
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            res = max(prod, res);
            if (nums[i] == 0) prod = 1.0;
        }
        
        prod = 1.0;
        
        // Backward pass
        for (int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            res = max(prod, res);
            if (nums[i] == 0) prod = 1.0;
        }
        
        return static_cast<int>(res);
    }
};