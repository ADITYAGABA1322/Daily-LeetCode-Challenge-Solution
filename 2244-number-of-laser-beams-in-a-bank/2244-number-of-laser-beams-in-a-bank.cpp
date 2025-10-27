class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0 , prev = 0;
        for(auto b : bank){
            int count = 0;
           for(char c : b) {if(c =='1') count++;}
           if(count) {ans += prev*count; prev = count;}
        }
        return ans;
    }
};