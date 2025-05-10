class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // do one thing just first cnt freq of 0 ni boht nums and check both sum first then do one thing take both sum which is max subtrach fomr another arr get diif of we get in that one before adding that diif for the no of zeros check is thier any 0 in which is max if yes add min val like 1 or 2 and after that getting difii add that diff no acc to the zeros we have in another one
        int n = nums1.size() , m = nums2.size();
        long long cnt1 = 0 , cnt2 = 0;
        long sum1 = 0 , sum2 = 0 , diff = 0;
        for(int i=0; i<n; i++){
            if(nums1[i] == 0)  cnt1++;
            sum1 += nums1[i];
        }
        for(int i=0; i<m; i++){
            if(nums2[i] == 0) cnt2++;
            sum2 += nums2[i];
        }
        long long minSum1 = sum1 + cnt1 , minSum2 = sum2 + cnt2;
        if(cnt1 == 0 && minSum1 < minSum2) return -1;
        if(cnt2 == 0 && minSum2 < minSum1) return -1;
        return max(minSum1 , minSum2);
    }
};