class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        long long currSum = 0 , maxSum = 0;
        int i = 0;
        for(int j=0; j<nums.size(); j++){
            while(st.find(nums[j]) != st.end()){
                st.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            currSum += nums[j];
            if(j-i+1 > k){
                st.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
            if(j-i+1 == k) maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};