class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        string res;
        for(int i=0; i<n; i++){
            res = max(res , word.substr(i , min(n - numFriends + 1 , n - i)));
        }
        return res;
    }
};