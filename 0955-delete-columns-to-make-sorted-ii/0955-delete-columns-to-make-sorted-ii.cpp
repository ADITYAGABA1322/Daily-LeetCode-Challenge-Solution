class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int m = s.size() , n = s[0].size();
        vector<bool> alreadySorted(m , false);
        int deletion = 0;
        for(int j=0; j<n; j++){
            bool isDeleted = false;
            for(int i=0; i<m-1; i++){
                if(!alreadySorted[i] && s[i][j] > s[i+1][j]){
                    deletion++;
                    isDeleted = true;
                    break;
                }
            }
            if(isDeleted){
                continue;
            }
            for(int i=0; i<m-1; i++){
                alreadySorted[i] = alreadySorted[i] | s[i][j] < s[i+1][j];
            }
        }
        return deletion;
    }
};