class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = 0 , l = 0, r = n-1;
        while(l <= r){
            while(l<r && nums[l] == nums[l+1]) l++;
            while(r>n && nums[r] == nums[r-1]) r--;
            int mid = l + (r-l)/2;
            if(nums[mid] < nums[res]) res = mid;
            else if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid - 1;
        }
        return nums[res];
    }
};