class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto c: letters){
            if(c > target) return c;
        }
        return letters[0];
    }
};