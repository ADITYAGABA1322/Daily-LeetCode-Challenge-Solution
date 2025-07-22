class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // Here we are given a problem in the form of we want to just remove the sub and give them some to like what is the sum of removing the simple just find the unique use the map in that case two or which is also been used to, which is really simple. I think after that we wanna trade to that and check those elements which are coming once and which are two or two point approach of sliding window works.
        unordered_set<int> seen;
        int left = 0 , sum = 0 , maxSum = 0;
        for(int right = 0; right<nums.size(); right++){
            while(seen.count(nums[right])){
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            sum += nums[right];
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};