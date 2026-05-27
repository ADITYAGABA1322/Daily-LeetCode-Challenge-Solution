class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> lastOcc(26 , -1) , firstCap(26 , -1);
        for(int i=0; i<n; i++){
            if(islower(word[i])) lastOcc[word[i] - 'a'] = i;
            else{
                if(firstCap[word[i] - 'A'] == -1) firstCap[word[i] - 'A'] = i;
            }
        }
        for(int i=0; i<26; i++){
            if(lastOcc[i] != -1 && firstCap[i] != -1 && lastOcc[i] < firstCap[i]) cnt++;
        }
        return cnt;
    }
};