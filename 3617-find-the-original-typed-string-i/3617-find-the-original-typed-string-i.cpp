class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size() , cnt = 1;
        for(int i=0; i<n-1; i++){
            // pass string now would which is  repeatinug  and repeat atmost  once means  so go thorugh the string find of pairs posible and return it 
            if(word[i] == word[i+1]) cnt++;
        }
        return cnt;
    }
};