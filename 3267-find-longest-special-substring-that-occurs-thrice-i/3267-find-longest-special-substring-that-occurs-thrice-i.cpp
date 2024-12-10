class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string , int > mp;
        for(int i=0; i<n; i++){
            string curr;
            for(int j=i; j<n; j++){
                if(curr.empty() || curr.back() == s[j]){
                    curr.push_back(s[j]);
                    mp[curr]++;
                }else{
                    break;
                }
            }
        }
        int ans = 0 ;
        for(auto it : mp){
            string str = it.first;
            if(it.second >= 3 && str.size() > ans ) ans = str.size();
        }
        if(ans == 0) return -1;
        return ans;
    }
};