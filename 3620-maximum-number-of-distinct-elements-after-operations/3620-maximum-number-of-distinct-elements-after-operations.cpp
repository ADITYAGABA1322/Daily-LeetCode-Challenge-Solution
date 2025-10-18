class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int distinctCount = 0 , lastAssigned = INT_MIN;
        for(auto num : nums){
            int min_val = num - k , max_val = num + k;
            int next_val = max(min_val , lastAssigned + 1);
            if(next_val <= max_val){
                lastAssigned = next_val;
                distinctCount++;
            }
        }
        return distinctCount;
    }
};