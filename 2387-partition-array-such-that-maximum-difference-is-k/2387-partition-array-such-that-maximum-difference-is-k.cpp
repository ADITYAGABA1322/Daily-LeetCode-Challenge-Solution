class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // given an int arr nums and an int k partition nums one or more subsequences such that each ele in nums appear exactly one of the subseq return min no of subseq needed such that diff b/w max andmin val ni each subseq atmost k ok 
        // brute force just simple take elle in such like that take ele in array fomr that arr and sych that max and min ele diff is atmost k means <= k ok and what we do first sort the array simply then  choose elel acc to that the diiff of max and min is <= k and return cnt of that 
        sort(nums.begin() , nums.end());
        int cnt = 1 , n = nums.size() , minVal = nums[0];
        for(int i=0; i<n; i++){
            if(nums[i] - minVal > k){
                cnt++;
                minVal = nums[i];
            }
        }
        return cnt;
    }
};