class Solution {
public:
    bool isPossible(vector<int>& nums , int k , int target){
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] <= target){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        // just 2 house which are not adjacent means nums[i] not take nums[i-1] and nums[i+1] ok bro  means take i += 2 ok not 1 and another just take k houses and  find the max and after we find the max in how many times then after that we find min  means we use what binary search but how should we sove this just find the apporach measn that we use isPossible to robe house means k is target 
        int n = nums.size();
        int left = 1 , right = 1e9;
        int maxi = 0;
        while(left < right){
            int mid = left + (right-left)/2;
            if(isPossible(nums , k , mid)){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }
};