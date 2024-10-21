class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return helper(s , 0 , st );
    }
    int helper(string &s , int start , unordered_set<string> &st){
        if(start == s.size()){
            return st.size();
        }
        int cnt = 0;
        for(int i=start+1 ; i<=s.size(); i++){
            string sub = s.substr(start , i - start);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                cnt = max(cnt , helper(s , i , st));
                st.erase(sub);
            }
        }
        return cnt;
    }
};