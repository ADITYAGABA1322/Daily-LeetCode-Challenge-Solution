class Solution {
public:
    bool isPossible(vector<int>& candies , long long k , long long target){
        if(target == 0) return true;
        long long piles = 0;
        for(auto  c : candies){
            piles+= c/target;
        }
        return piles>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long  maxi = 0;
        for(auto c : candies){
            maxi = max(maxi , (long long)c);
        }
        long long left = 0 ,right = maxi;
        while(left < right){
            long long mid = left + (right-left+1)/2;
            if(isPossible(candies , k , mid)){
                left  = mid;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};