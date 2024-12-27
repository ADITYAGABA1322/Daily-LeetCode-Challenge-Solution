class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // given arr val[i]  represent to ith sighseeing spot  two sight seeing spots i and j dis j-i them The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.  maximum score of a pair of sightseeing spots. return ok  simple fund max 2 ele. and sub index of that ok 
        int max_i = values[0] + 0;
        int maxS = INT_MIN;
        for(int j=1; j<values.size(); j++){
            maxS = max(maxS , max_i + values[j] - j);
            max_i = max(max_i , values[j]+j);
        }
        return maxS;
    }
};