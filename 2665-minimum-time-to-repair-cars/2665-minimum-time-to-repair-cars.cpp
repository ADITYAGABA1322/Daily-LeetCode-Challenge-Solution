class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars , long long time){
        long long totalCars = 0;
        for(auto r : ranks){ 
            totalCars += sqrt(time/r);
            if(totalCars >= cars) return true;
        }
        return false;
    } 
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = *min_element(ranks.begin() , ranks.end());
        int n = ranks.size();
        long long left = 0 , right = (long long) minRank*cars*cars;
        while(left < right){
            // now here why we do sort just do one thing take cars as target means in possible and we nned to return min time also
            long long mid = left + (right - left ) / 2;
            if(isPossible(ranks , cars , mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};