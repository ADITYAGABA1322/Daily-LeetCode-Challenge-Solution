class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<int> rightSideMatch(n , 0);
        int rightMatched = 0;
        int i = n-1 , j = m-1;
        while(i>=0){
            if(j>=0 && word1[i] == word2[j]){
                rightMatched++;
                j--;
            }
            rightSideMatch[i] = rightMatched;
            i--;
        }
        i = 0 , j = 0;
        vector<int> seq;
        bool changePower = true;
        while(i < n && j<m){
            if(word1[i] == word2[j]){
                seq.push_back(i);
                j++;
            } else if(changePower == true && i+1 < n && rightSideMatch[i+1] >= m-j-1){
                seq.push_back(i);
                j++;
                changePower = false;
            }
            i++;
        }
        return j == m ? seq : vector<int>();
    }
};