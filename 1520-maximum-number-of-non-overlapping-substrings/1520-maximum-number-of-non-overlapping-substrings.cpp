class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26 , -1);
        vector<int> last(26 , -1);
        for(int i=0; i<n; i++){
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
        }
        for(int i=n-1; i>=0; i--){
            if(last[s[i] - 'a'] == -1) last[s[i] - 'a'] = i;
        }
        vector<pair<int , int>> cand;
        for(int c=0; c<26; c++){
            if(first[c] == -1) continue;
            int L = first[c] , R = last[c];
            bool valid = true;
            for(int i=L; i<=R; i++){
                R = max(R , last[s[i] - 'a']);
                if(first[s[i] - 'a'] < L){
                    valid = false;
                    break;
                }
            }
            if(valid) cand.push_back({L , R});
        }
        sort(cand.begin() , cand.end() , [](pair<int , int> a , pair<int , int> b){
            return a.second < b.second;
        });
        int lastEnd = -1;
        vector<string> res;
        for(int i=0; i<cand.size(); i++){
            if(cand[i].first > lastEnd){
                lastEnd = cand[i].second;
                res.push_back(s.substr(cand[i].first , cand[i].second - cand[i].first + 1)); 
            }
        }
        return res;
    }
};