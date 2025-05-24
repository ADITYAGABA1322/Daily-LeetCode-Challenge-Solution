class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        // for(int i=0; i<words.size(); i++){
        //     bool isFound = false;
        //     for(int j=0; j<words[i].size(); j++){
        //         if(words[i][j] == x){
        //             isFound = true;
        //             break;
        //         }
                
        //     }
        //     if(isFound) res.push_back(i);
        // }
        for(int i=0; i<words.size(); i++){
            if(words[i].find(x) != string::npos){
                res.push_back(i);
            }
        }
        return res;
    }
};