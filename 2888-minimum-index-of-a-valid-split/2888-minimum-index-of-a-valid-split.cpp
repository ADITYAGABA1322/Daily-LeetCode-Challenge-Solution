class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //   an element x of an int arr of len m is dominant , if more than half the element of arr have a value x  we nened to split it acc to roeated or dominant ele comes in both  return the min valid split or -1 ok  just osrt it and use map to check frreq if that elle acc to that we split it and return that index done 
        int domiEle = -1 , maxFreq = 0 , n = nums.size();
        unordered_map<int , int> freq;
        for(auto n : nums){
            freq[n]++;
            if(freq[n] > maxFreq){
                maxFreq = freq[n];
                domiEle = n;
            }
        }

        if(maxFreq *2 <= n) return -1;
        int leftCnt = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == domiEle) leftCnt++;
            int leftSz = i+1 , rightSz = n - leftSz , rightCnt = maxFreq - leftCnt;
            if(leftCnt * 2 > leftSz && rightCnt*2 > rightSz) return i;
        }
        return -1;
    }
};