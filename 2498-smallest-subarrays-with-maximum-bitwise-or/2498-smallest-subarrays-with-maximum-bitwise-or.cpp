class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> lastPos(30, -1); // Track last position of each bit (0-29)
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Update last positions for bits in current number
            for (int bit = 0; bit < 30; bit++) {
                if ((nums[i] >> bit) & 1) {
                    lastPos[bit] = i;
                }
            }
            
            // Find the rightmost position we need to reach
            // to get maximum possible OR starting from i
            int maxReach = i; // At least include current element
            for (int bit = 0; bit < 30; bit++) {
                if (lastPos[bit] != -1) {
                    maxReach = max(maxReach, lastPos[bit]);
                }
            }
            
            result[i] = maxReach - i + 1;
        }
        
        return result;
    }
};