// brute force -> approach
// dekhke khyal ki range hi sb kuch and lexo nikal lenge lekin range ko dekhke 
// main toh fomrula lexograhoical pta ha toh sab asan ha
//  cases for 10 th, 1-
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curr = 1;
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(curr);
            if(curr*10 <= n) curr *= 10;
            else{
                if(curr>=n) curr/=10;
                 curr++;
                while(curr % 10 == 0){
                    curr /= 10;
                }
            }
        }
        return res;
    }
};