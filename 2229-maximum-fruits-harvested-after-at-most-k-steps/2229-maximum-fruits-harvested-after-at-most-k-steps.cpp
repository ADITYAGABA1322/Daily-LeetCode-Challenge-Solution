class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // After analyzing the program, what I see I found one thing there is one start position and we need to take the K steps. It's depend on a person to go either side or right side in which where it find the maximum profit or the max number of fruits, so how do this thing is happening in the optimal way it's similar like if I say take it or not take like a problem using DP or greedy approach I think either works. Let's not talk about the approach. Let's analyze the problem first let me in the between I get a index and I want to see either go left either go right and take the four steps. Four steps is depend on the key steps how much let's take an example start position is equal to 5K equal to four now I want to move either left side or right side and take the key steps according to that now I can move to four steps. and there is one condition you can harvest from from the ned if possible if not tkae left or right to take max fruits  there is a left right concept shoudlwe use 2 pointer or binary search or prefix sum too a
        int left = 0 , right = 0 , n = fruits.size() , sum = 0 , ans = 0;
        auto steps = [&](int left ,  int right) -> int {
            if(fruits[right][0] <= startPos){
                return startPos - fruits[left][0];
            } else if(fruits[left][0]  >= startPos){
                return fruits[right][0] - startPos;
            } else{
                return min(abs(startPos - fruits[right][0]),
                           abs(startPos - fruits[left][0])) +
                       fruits[right][0] - fruits[left][0];
            }
        };

        while(right < n){
            sum += fruits[right][1];
            while(left <= right && steps(left , right) > k){
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans , sum);
            right++;
        }
        return ans;
    }
};