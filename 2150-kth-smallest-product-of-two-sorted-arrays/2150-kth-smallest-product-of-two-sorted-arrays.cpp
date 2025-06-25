class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10 , right = 1e10;
        while(left < right){
            long long mid = left + (right - left) / 2;
            if(countProductsLessOrEqual(nums1 , nums2 , mid) < k) left = mid+1;
            else right = mid;
        }
        return left;
    }

    long long countProductsLessOrEqual(vector<int>& nums1 , vector<int>& nums2 , long long threshold){
        long long cnt = 0;
        for(auto num1: nums1){
            if(num1 > 0){
                long long left = 0 , right = nums2.size() - 1;
                while(left <= right){
                    long long mid = left + (right - left) / 2;
                    if((long long) num1 * nums2[mid] <= threshold) left = mid+1;
                    else right = mid - 1;
                }
                cnt += left;
            }
            else if(num1 < 0){
                 long long left = 0 , right = nums2.size() - 1;
                while(left <= right){
                    long long mid = left + (right - left) / 2;
                    if((long long) num1 * nums2[mid] <= threshold) right = mid-1;
                    else left = mid + 1;
                }
                cnt += nums2.size() - left;
            }
            else{
                if(threshold >= 0){
                    cnt += nums2.size();
                }
            }
        }
        return cnt;
    }
};