class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size(), cnt = 0 , res = 0;
        unordered_set<int> broken(begin(brokenLetters) , end(brokenLetters));
        for(int i=0; i<=n; i++){
            if(i == n || text[i] ==' '){
                res += cnt == 0;
                cnt = 0;
            } else if(cnt == 0){
                cnt += broken.count(text[i]);
            }
        }
        return res;
    }
};