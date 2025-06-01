class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for(int a=0; a<=min(n , limit); a++){
            // for(int j=0; j<=min(n-i , limit); j++){
            //     int k = n - i - j;
            //     if(k<=limit) cnt++;
            // }
            int rem = n -a;
            int maxB = min(rem , limit);
            int minC = max(0 , rem - limit);
            if(minC <= maxB) cnt += (maxB - minC + 1);
        }
        return cnt;
    }
};