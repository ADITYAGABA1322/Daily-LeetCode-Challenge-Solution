class Solution {
public:
    int reverseNum(int n){
        int rev = 0;
        while(n > 0){
            rev = rev*10 + n%10;
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        // just  iterate the nums pure simulation do one thing check number whhihc revrse is ther if it threr calucate dist and return min if not return -1 take res = INT_MAX and find min  but how ietare it use one func of reverse in revrse just swap the digit place and check it and leading zeroes rmoeve it means conitnue if 0 at last index not count it simple reutrn min abs index  edge case -> palindrome and dupliacte 
        unordered_map<int , int> mp;
        int res = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(mp.count(nums[i])){
                res = min(res , i - mp[nums[i]]);
            }   
             mp[reverseNum(nums[i])] = i;  
        }
        return res == INT_MAX ? -1 : res;
    }
};