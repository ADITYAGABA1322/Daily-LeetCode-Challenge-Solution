class Solution {
public:
    int rev(int n){
        int curr = 0;
        while(n > 0){
        curr =  curr * 10 + n % 10;
        n /= 10;
        }
        return curr;
    }
    int mirrorDistance(int n) {
        return abs(n - rev(n));        
    }
};