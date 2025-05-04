class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // brute force
        // int n = dominoes.size()  , cnt = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int a = dominoes[i][0] , b = dominoes[i][1];
        //         int c = dominoes[j][0] , d = dominoes[j][1];
        //         if((a == c && b == d) || (a == d && b == c)) cnt++;
        //     }
        // }
        // return cnt;
        // optimized 
        unordered_map<int , int> mp;
        int cnt = 0;
        for(auto d : dominoes){
            int key = min(d[0] , d[1]) * 10 + max(d[0] , d[1]);
            cnt += mp[key];
            mp[key]++;
        }
        return cnt;
    }
};