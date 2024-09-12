class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        unordered_set<char> set(allowed.begin() , allowed.end());
        for(auto word : words){
            bool isConsis = true;
            for(auto ch : word){
            if(set.find(ch) == set.end()){
                isConsis = false;
                break;
            }
            }
            if(isConsis) cnt++;
        }
        return cnt;
    }
};