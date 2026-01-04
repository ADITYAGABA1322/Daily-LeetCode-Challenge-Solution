class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            res += findFourD(nums[i]);
        }
        return res;
    }
    int findFourD(int num){
        int sum = 0 , divisior = 0;
        for(int fact = 1 ; fact*fact <= num; fact++){
            if(num % fact == 0){
                int otherF = num/fact;
                if(otherF == fact) {
                    divisior += 1;
                    sum += fact;
                }
                else {
                    divisior += 2;
                    sum += fact + otherF;
                }
            }
            if(divisior > 4) return 0;
        }
        return divisior == 4 ? sum : 0;
    }
};