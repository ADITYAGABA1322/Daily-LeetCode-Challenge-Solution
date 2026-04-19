class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() , n = nums2.size();
        int i = 0 , j = 0 , res = 0;
        while(i<m && j<n){
            if(nums1[i] > nums2[j]) i++;
            else res = max(res , j - i);
            j++;
        }
        return res;
    }
};