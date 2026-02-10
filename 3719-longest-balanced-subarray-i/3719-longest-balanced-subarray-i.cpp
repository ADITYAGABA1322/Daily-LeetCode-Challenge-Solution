class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            set<int> even , odd;
            for(int j=i; j<n; j++){
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(even.size() == odd.size())  maxLen = max(maxLen , j-i+1);
        }   
        }
        return maxLen;
    }
};