class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // if i am talking about this question  is simply straight forward what we want to do now like we want o find the longest fiobnacii subseq ok it simple as we perform dp in fib we want o do simaler but we find subseq means finding out the fib elel inthe arr that what i say if talk about fib matain base condition for start 0 and 1  ele and after just do dp[i-1] + dp[i-2] ok just tow prev to form new one this one is about fibo and now we want to perform longest subsequence as we perform using dp for i perfomr +1 in dp to find next ok 
        unordered_map<int , int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]] = i;
        vector<vector<int>> dp(arr.size() , vector<int>(arr.size() , 2));
        int maxLen = 0;
        for(int j=1; j<arr.size(); j++){
            for(int i=0; i<j; i++){
                int k = mp.find(arr[j] - arr[i]) != mp.end() ? mp[arr[j]-arr[i]]:-1;
                if(k>=0 && k< i){
                    dp[i][j] = dp[k][i] + 1;
                    maxLen = max(maxLen , dp[i][j]);
                }
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
};