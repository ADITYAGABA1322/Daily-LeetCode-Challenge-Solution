class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        if(low % 2 == 0) low++;
        if(high % 2 == 0) high--;
        if(low <= high) cnt += (high - low) /2 +1;
        return cnt;
    }
};
