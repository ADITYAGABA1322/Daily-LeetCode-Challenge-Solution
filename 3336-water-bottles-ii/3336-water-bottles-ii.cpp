class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int maxi = numBottles , cnt = 0;
        while(maxi >= numExchange){
            maxi = maxi - numExchange + 1;
            numExchange++;
            cnt++;
        }
        return numBottles + cnt;
    }
};