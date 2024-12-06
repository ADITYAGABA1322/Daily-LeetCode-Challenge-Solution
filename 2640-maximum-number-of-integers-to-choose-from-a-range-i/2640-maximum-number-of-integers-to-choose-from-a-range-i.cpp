class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // banned array 2 intgers n and max sum  chosse int b/w 1 to n ok each integer atmost once ok duplicate not allowed choose int ok not in banned array and sum not exceed max sum simple apporach just using set  take i < n and j to banned and check consiton s done 
        unordered_set<int> bannedSet(banned.begin() , banned.end());
        int currSum = 0 , cnt = 0;
        for(int i=1; i<=n ; i++){
            if(bannedSet.find(i) == bannedSet.end() && currSum + i <= maxSum){
                currSum += i;
                cnt++;
            }
        }
        return cnt;
    }
};