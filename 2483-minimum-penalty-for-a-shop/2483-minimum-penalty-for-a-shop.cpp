class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size() , earliestH = 0 , currP = 0 , minP = 0;
        for(int i=0; i<n; i++){
            if(customers[i] == 'N') currP++;
            else currP--;
             if(currP < minP){
            minP = currP;
            earliestH = i+1;
        }
        }
        return earliestH;
    }
};