class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // just a simple problme using the hasmap ohw we nned to pair for indices and nums  ok and accrding to that we use pair of indices and numss if mp.find != mp.end means we go the contions accrding to we check first iterate through indices in pair like 0 1 and we j - i != nums[j] - nums[i]. only if i < j and then cnt it and return and we are done ok 
        unordered_map<int , int> diffCnt;
        long long totalPair = 0 , goodPair = 0;
        for(int i=0; i<nums.size(); i++){
            int diff = i - nums[i];
            if(diffCnt.find(diff) != diffCnt.end()){
                goodPair += diffCnt[diff];
            }
            diffCnt[diff]++;
            totalPair += i; 
        }
        return totalPair - goodPair;
    }
};