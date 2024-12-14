class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // given 0 index nums a subarray cnotinuius if nums[i1] - nums[i2] <= 2 return total no of continuous subarray
        // nums = 5,4,2,4 -> continuos subarray we find we use simple dp 2 pointer easily we find it and use map or set also lets implemmnt the approach for 2 pointer hust using left and right using thes 2 pointer we dinf that the conditon operation to check the continuos ok and cnt and return it 
        int n = nums.size() , i = 0;
        long long cnt = 0;
        multiset<int> st;
        for(int j=0; j<n; j++){
            st.insert(nums[j]);
            while(*st.rbegin() - *st.begin() > 2){
                st.erase(st.find(nums[i]));
                i++;
            }
            cnt += j-i+1;
        }
        return cnt;
    } 
};