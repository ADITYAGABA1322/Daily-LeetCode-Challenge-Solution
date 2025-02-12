class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // given 0 ind arr nums consisting  +ve int choose i and j , such i != j 
        // now we use the hasp map herre to check the pair and use mp.find and check through end with num to nums end if yes we return the max val of that ok 
        unordered_map<int , int>mp;
        int maxSum = -1;
        auto digitSum = [](int num){
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            return sum;
        };
        for(auto num : nums){
            int digNum = digitSum(num);
            if(mp.find(digNum) != mp.end()){
                maxSum = max(maxSum , mp[digNum] + num);
            }
            mp[digNum] = max(mp[digNum] , num);
        }
        return maxSum;
    }
};