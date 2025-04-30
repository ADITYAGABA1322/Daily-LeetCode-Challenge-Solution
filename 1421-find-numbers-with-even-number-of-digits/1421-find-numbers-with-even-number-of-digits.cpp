class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int  res = 0;
        for(auto num : nums){
            int cnt = 0;
            if(num == 0) cnt = 1;
            else{
            while(num > 0){
                 cnt++;
                num /= 10;
            }
            }
            if(cnt % 2 == 0) res++;
        }
        return res;
    }
};