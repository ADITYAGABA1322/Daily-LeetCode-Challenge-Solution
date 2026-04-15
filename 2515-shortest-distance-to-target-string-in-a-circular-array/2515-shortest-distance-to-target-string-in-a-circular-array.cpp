class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size() , res = INT_MAX;
        for(int i=0; i<n; i++){
            if(words[i] == target){
            int stDist = abs(i - startIndex);
            int circularDist = n - stDist;
            res = min({res , stDist , circularDist});
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};