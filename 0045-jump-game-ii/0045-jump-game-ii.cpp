class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size() , maxIndex = 0 , curr  = 0 , jump = 0;
        // int i=0 , j = 0 , res = 0;
        // while(j<n-1){
        //     int maxIndex = j;
        //     for(int k=i; k<=j; k++) maxIndex = max(maxIndex ,  k + nums[k]);
        //     i=j+1;
        //     j = maxIndex;
        //     res++;
        // }
        // return res;
        for(int i=0; i<n-1; i++){
            maxIndex = max(maxIndex , i+nums[i]);
            if(curr  == i){
                jump++;
                curr = maxIndex;
            }
        }
        return jump;
    }
};