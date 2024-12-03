class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // simple iterate through a  spaces and then check string s and then add space done make it optimal using the map i think is best or not i think 2 pointer  woking here one pointer itrate string one is checking the spaces by spaces array i think its work
        int n = s.size() , m = spaces.size();
        int j=0;
        string res;
        for(int i=0; i<n; i++){
            if(j < m && i == spaces[j]){
                res += ' ';
                j++;
            }
            res += s[i];
        }
        return res;
    }
};