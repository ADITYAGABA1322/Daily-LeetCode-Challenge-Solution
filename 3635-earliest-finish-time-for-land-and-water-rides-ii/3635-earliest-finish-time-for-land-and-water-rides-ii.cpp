class Solution {
public:
    int finshLandWater(vector<int> st1 , vector<int> t1 , vector<int> st2 , vector<int> t2){
        int finish1 = INT_MAX;
        for(int i=0; i<st1.size(); i++){
            finish1 = min(finish1 , st1[i] +t1[i]);
        }
        int finish2 = INT_MAX;
        for(int i=0; i<st2.size(); i++){
            finish2 = min(finish2 , max(finish1 , st2[i]) + t2[i]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res1 = finshLandWater(landStartTime , landDuration, waterStartTime , waterDuration);
        int res2 = finshLandWater(waterStartTime , waterDuration, landStartTime, landDuration);
        return min(res1 , res2);
    }
};